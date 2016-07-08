# Generated by org.mangosdk.spi.processor.SpiProcessor (0.2.4)
# Fri, 8 Jul 2016 17:08:23 +0400
*
*    that was changed.
* $Id$
* $URL$
* ----------------------------------------------------------------------------
* 1. The University of Tuebingen, Germany
* 2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
* 3. The California Institute of Technology, Pasadena, CA, USA
* 4. The University of California, San Diego, La Jolla, CA, USA
* 5. The Babraham Institute, Cambridge, UK
* @author Finja B&uuml;chel
* @date $Date$
* @param level
* @param newValue  The new value of the property.
* @param oldValue  The old value of the property.
* @param propertyName  The programmatic name of the property
* @param qualChangeEvent the event to clone.
* @param source  The bean that fired the event.
* @param version
* @return
* @return  true is the source is set.
* @return {@code true} is the new value is set.
* @return {@code true} is the old value is set.
* @see java.lang.Object
* @see java.util.EventObject
* @since 1.0
* @version $Rev$
* Constructs a new {@code PropertyChangeEvent}.
* Constructs a new {@link PropertyChangeEvent}, cloned from
* Contains some constants related to the qual package.
* Copyright (C) 2009-2016 jointly by the following organizations:
* Generated serial version identifier.
* Returns {@code true} is the new value is set.
* Returns {@code true} is the old value is set.
* Returns {@code true} is the source is set.
* The latest namespace URI of this parser, this value can change between releases.
* The namespace URI of this parser for SBML level 3, version 1 and package version 1.
* The short name/label of the package
* This file is part of JSBML. Please visit <http://sbml.org/Software/JSBML>
* This library is free software; you can redistribute it and/or modify it
* and also available online as <http://sbml.org/Software/JSBML/License>.
* for the latest version of JSBML and more information about SBML.
* in the file named "LICENSE.txt" included with this software distribution
* the Free Software Foundation. A copy of the license agreement is provided
* the given {@code qualChangeEvent}.
* under the terms of the GNU Lesser General Public License as published by
*/
.getPropertyName(), qualChangeEvent.getOldValue(),
/*
/* (non-Javadoc)
/**
@Override
Object newValue) {
TreeNodeChangeEvent tnce = (TreeNodeChangeEvent) object;
boolean equals = tnce.isSetSource() == isSetSource();
equals &= tnce.getNewValue().equals(getNewValue());
equals &= tnce.getOldValue().equals(getOldValue());
equals &= tnce.getSource().equals(getSource());
equals &= tnce.isSetNewValue() == isSetNewValue();
equals &= tnce.isSetOldValue() == isSetOldValue();
final int prime = 13;
hashCode += prime * getNewValue().hashCode();
hashCode += prime * getOldValue().hashCode();
hashCode += prime * getSource().hashCode();
if (equals && isSetNewValue()) {
if (equals && isSetOldValue()) {
if (equals && isSetSource()) {
if (isSetNewValue()) {
if (isSetOldValue()) {
if (isSetSource()) {
if (object.getClass().equals(getClass())) {
import java.beans.PropertyChangeEvent;
import java.util.ArrayList;
import java.util.List;
import javax.swing.tree.TreeNode;
import org.sbml.jsbml.SBase;
import org.sbml.jsbml.util.TreeNodeChangeEvent;
int hashCode = getClass().getName().hashCode();
namespaces = new ArrayList<String>();
namespaces.add(namespaceURI_L3V1V1);
package org.sbml.jsbml.ext.qual;
private static final long serialVersionUID = 944717095818356337L;
public QualConstants clone() {
public QualConstants(QualConstants qualChangeEvent) {
public QualConstants(SBase source, String propertyName, Object oldValue,
public TreeNode getSource() {
public boolean equals(Object object) {
public boolean isSetNewValue() {
public boolean isSetOldValue() {
public boolean isSetSource() {
public class QualConstants  extends PropertyChangeEvent {
public int hashCode() {
public static String getNamespaceURI(int level, int version) {
public static final List<String> namespaces;
public static final String compartment         = "compartment";
public static final String constant            = "constant";
public static final String initialLevel        = "initialLevel";
public static final String maxLevel            = "maxLevel";
public static final String name                = "name";
public static final String namespaceURI = namespaceURI_L3V1V1;
public static final String namespaceURI_L3V1V1 = "http://www.sbml.org/sbml/level3/version1/qual/version1";
public static final String outputLevel         = "outputLevel";
public static final String packageName = "Qualitative";
public static final String qualitativeSpecies  = "qualitativeSpecies";
public static final String rank                = "rank";
public static final String resultLevel         = "resultLevel";
public static final String shortLabel = "qual";
public static final String sign                = "sign";
public static final String thresholdLevel      = "thresholdLevel";
public static final String transitionEffect    = "transitionEffect";
qualChangeEvent.getNewValue());
return (TreeNode) super.getSource();
return equals;
return false;
return getNewValue() != null;
return getOldValue() != null;
return getSource() != null;
return hashCode;
return namespaceURI;
return new QualConstants(this);
static {
super(source, propertyName, oldValue, newValue);
this((SBase) qualChangeEvent.getSource(), qualChangeEvent
}
