<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
  <h2>Nice doc, doc</h2>
  <xsl:apply-templates/>
  </body>
  </html>
</xsl:template>

<xsl:template match="cd">
  <p>
  <xsl:apply-templates select="title"/>
  <xsl:apply-templates select="artist"/>
  </p>
</xsl:template>

<xsl:template match="titre">
  Title: <span style="color:#ff0000">
  Ceci est un titre</span>
  <br />
</xsl:template>

<xsl:template match="auteur">
  Auteur <span style="color:#00ff00">
  Ceci est un auteur</span>
  <br />
</xsl:template>
<xsl:template match="prenom">
  Prenom <span style="color:#00ff00">
  Ceci est un prenom</span>
  <br />
</xsl:template>
<xsl:template match="chapitre">
  Chapitre <span style="color:#00ff00">
  Ceci est un chapitre</span>
  <br />
</xsl:template>

</xsl:stylesheet>