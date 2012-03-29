<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
  <h2>Document</h2>
  <xsl:apply-templates/>
  </body>
  </html>
</xsl:template>

<xsl:template match="titre">
  Titre : <span style="color:#ff0000">
  <b><xsl:value-of/></b></span>
  <br/>
</xsl:template>

<xsl:template match="auteur">
  <b>Auteur : </b><br/><xsl:apply-templates/><br/>
</xsl:template>

<xsl:template match="nom">
  Nom : <span style="color:#00ff00">
   <xsl:value-of/></span>
  <br/>
</xsl:template>

<xsl:template match="prenom">
  Prenom : <span style="color:#00ff00">
   <xsl:value-of/></span>
  <br/>
</xsl:template>

<xsl:template match="resume">
  Resume : <span style="color:#00ff00">
   <xsl:value-of/></span>
  <br/>
</xsl:template>

<xsl:template match="chapitre">
  <xsl:value-of/>
</xsl:template>

</xsl:stylesheet>
