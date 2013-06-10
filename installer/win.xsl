<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0"
   xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
   xmlns:wix="http://schemas.microsoft.com/wix/2006/wi">
  <xsl:output indent="yes" method="xml"/>

  <xsl:template match="/wix:Wix">
    <Wix xmlns="http://schemas.microsoft.com/wix/2006/wi">
      <Product xmlns="http://schemas.microsoft.com/wix/2006/wi" Id="{0F0B1744-A6B2-48DD-AEC3-E22E6C106825}" Name="OpenGamma" Language="1033" Version="1.0" Manufacturer="OpenGamma, Inc." UpgradeCode="{0F0B1744-A6B2-48DD-AEC3-E22E6C106825}">
        <Package InstallerVersion="200" Compressed="yes" />
        <Media Id="1" Cabinet="media1.cab" EmbedCab="yes" />
        <Directory Id="TARGETDIR" Name="SourceDir" />
        <Feature Id="LIBIZY" Title="LibIZY" Level="1">
          <!-- Start Ripping through the xml -->
          <xsl:apply-templates select="wix:Fragment" />
        </Feature>

        <!--Tack on your specific wix options-->
        <UIRef Id="WixUI_Minimal" />
        <UIRef Id="WixUI_ErrorProgressText" />
        <!-- TODO: Add Wix Specific Dialogs and features. -->
        <!-- TODO: Add artwork  -->
        <!-- TODO: Add ... -->

      </Product>

      <!--Output the fragment info which heat generates-->
      <xsl:copy-of select="./*" />
            
    </Wix>
  </xsl:template>

  <!-- Unused atm
  <xsl:template match="wix:File">      
  </xsl:template>-->

  <xsl:template match="wix:Component">
    <xsl:element name="ComponentRef" xmlns="http://schemas.microsoft.com/wix/2006/wi" >
      <xsl:attribute name="Id">
        <xsl:value-of select="@Id" />
      </xsl:attribute>
    </xsl:element>
  </xsl:template>

  <xsl:template match="wix:Directory">
    <xsl:apply-templates select="wix:Component" />
    <xsl:apply-templates select="wix:Directory" />
  </xsl:template>

  <xsl:template match="wix:DirectoryRef">
    <xsl:apply-templates select="wix:Component" />
    <xsl:apply-templates select="wix:Directory" />
  </xsl:template>

  <xsl:template match="wix:Fragment">
    <xsl:apply-templates select="wix:DirectoryRef" />
  </xsl:template>

</xsl:stylesheet>
