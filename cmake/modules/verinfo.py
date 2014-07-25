#
# Copyright (C) 2014 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

import platform, sys, subprocess, time
from yaml import load, dump
try:
    from yaml import CLoader as Loader, CDumper as Dumper
except ImportError:
    from yaml import Loader, Dumper

def get_bits():
    process = subprocess.Popen(['gcc', '-dumpmachine'], stdout=subprocess.PIPE)
    machine, unused_err = process.communicate()
    retcode = process.poll()
    if retcode:
        raise RuntimeError('Error using gcc -dumpmachine')
    if machine[0:4] == 'i686':
        return 32
    else:
        return 64

def platform_code():
    """Returns the current platform code, following the usual convention
    for OG-Maths."""
    p = platform.system()
    if p == 'Linux':
        return 'lnx'
    elif p == 'Darwin':
        return 'osx'
    elif p =='Windows':
        if get_bits() == 32:
            return 'w32'
        else:
            return 'win'
    else:
        raise NotImplementedError('This platform (%s) is not recognised.' % p)

def generate_verinfo(project, revision, buildnumber):
    try:
        buildnumber = int(buildnumber)
    except ValueError:
        pass
    d = { 'project': project, 'revision': revision, \
          'platforms': [platform_code()],
          'buildnumber': buildnumber,
          'localtime': time.strftime('%Y/%m/%d %H:%M:%S'),
          'timestamp': time.time() }
    return d

def main():
    if len(sys.argv) != 3:
        print "Usage: verinfo.py <output_file> <build number>"
        return 1

    process = subprocess.Popen(['git', 'rev-parse', 'HEAD'], stdout=subprocess.PIPE)
    rev, unused_err = process.communicate()
    retcode = process.poll()
    if retcode:
        raise RuntimeError('Error getting SHA1 of git HEAD')

    with open(sys.argv[1],'w') as f:
        f.write(dump(generate_verinfo('OG-Izy', rev.strip(), sys.argv[2]), Dumper=Dumper))
    return 0

if __name__ == '__main__':
    sys.exit(main())
