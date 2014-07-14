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

def platform_code():
    p = platform.system()
    if p == 'Linux':
        return 'lnx'
    elif p == 'Darwin':
        return 'osx'
    else:
        return 'win'

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
