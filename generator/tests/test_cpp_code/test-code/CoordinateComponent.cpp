/**
 * @file CoordinateComponent.cpp
 * @brief Implementation of the CoordinateComponent class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sbml/packages/spatial/sbml/CoordinateComponent.h>
#include <sbml/packages/spatial/sbml/ListOfCoordinateComponents.h>
#include <sbml/packages/spatial/validator/SpatialSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new CoordinateComponent using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 */
CoordinateComponent::CoordinateComponent(unsigned int level,
                                         unsigned int version,
                                         unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mType (COORDINATE_KIND_INVALID)
  , mUnit ("")
  , mBoundaryMin (NULL)
  , mBoundaryMax (NULL)
{
  setSBMLNamespacesAndOwn(new SpatialPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new CoordinateComponent using the given SpatialPkgNamespaces
 * object.
 */
CoordinateComponent::CoordinateComponent(SpatialPkgNamespaces *spatialns)
  : SBase(spatialns)
  , mId ("")
  , mType (COORDINATE_KIND_INVALID)
  , mUnit ("")
  , mBoundaryMin (NULL)
  , mBoundaryMax (NULL)
{
  setElementNamespace(spatialns->getURI());
  connectToChild();
  loadPlugins(spatialns);
}


/*
 * Copy constructor for CoordinateComponent.
 */
CoordinateComponent::CoordinateComponent(const CoordinateComponent& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mType ( orig.mType )
  , mUnit ( orig.mUnit )
  , mBoundaryMin ( NULL )
  , mBoundaryMax ( NULL )
{
  if (orig.mBoundaryMin != NULL)
  {
    mBoundaryMin = orig.mBoundaryMin->clone();
  }

  if (orig.mBoundaryMax != NULL)
  {
    mBoundaryMax = orig.mBoundaryMax->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for CoordinateComponent.
 */
CoordinateComponent&
CoordinateComponent::operator=(const CoordinateComponent& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mType = rhs.mType;
    mUnit = rhs.mUnit;
    delete mBoundaryMin;
    if (rhs.mBoundaryMin != NULL)
    {
      mBoundaryMin = rhs.mBoundaryMin->clone();
    }
    else
    {
      mBoundaryMin = NULL;
    }

    delete mBoundaryMax;
    if (rhs.mBoundaryMax != NULL)
    {
      mBoundaryMax = rhs.mBoundaryMax->clone();
    }
    else
    {
      mBoundaryMax = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CoordinateComponent object.
 */
CoordinateComponent*
CoordinateComponent::clone() const
{
  return new CoordinateComponent(*this);
}


/*
 * Destructor for CoordinateComponent.
 */
CoordinateComponent::~CoordinateComponent()
{
  delete mBoundaryMin;
  mBoundaryMin = NULL;
  delete mBoundaryMax;
  mBoundaryMax = NULL;
}


/*
 * Returns the value of the "id" attribute of this CoordinateComponent.
 */
const std::string&
CoordinateComponent::getId() const
{
  return mId;
}


/*
 * Returns the value of the "type" attribute of this CoordinateComponent.
 */
CoordinateKind_t
CoordinateComponent::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this CoordinateComponent.
 */
const std::string&
CoordinateComponent::getTypeAsString() const
{
  static const std::string code_str = CoordinateKind_toString(mType);
  return code_str;
}


/*
 * Returns the value of the "unit" attribute of this CoordinateComponent.
 */
const std::string&
CoordinateComponent::getUnit() const
{
  return mUnit;
}


/*
 * Predicate returning @c true if this CoordinateComponent's "id" attribute is
 * set.
 */
bool
CoordinateComponent::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this CoordinateComponent's "type" attribute
 * is set.
 */
bool
CoordinateComponent::isSetType() const
{
  return (mType != COORDINATE_KIND_INVALID);
}


/*
 * Predicate returning @c true if this CoordinateComponent's "unit" attribute
 * is set.
 */
bool
CoordinateComponent::isSetUnit() const
{
  return (mUnit.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this CoordinateComponent.
 */
int
CoordinateComponent::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "type" attribute of this CoordinateComponent.
 */
int
CoordinateComponent::setType(const CoordinateKind_t type)
{
  if (CoordinateKind_isValid(type) == 0)
  {
    mType = COORDINATE_KIND_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this CoordinateComponent.
 */
int
CoordinateComponent::setType(const std::string& type)
{
  if (CoordinateKind_isValidString(type.c_str()) == 0)
  {
    mType = COORDINATE_KIND_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = CoordinateKind_fromString(type.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "unit" attribute of this CoordinateComponent.
 */
int
CoordinateComponent::setUnit(const std::string& unit)
{
  if (!(SyntaxChecker::isValidInternalUnitSId(unit)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mUnit = unit;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "id" attribute of this CoordinateComponent.
 */
int
CoordinateComponent::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "type" attribute of this CoordinateComponent.
 */
int
CoordinateComponent::unsetType()
{
  mType = COORDINATE_KIND_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "unit" attribute of this CoordinateComponent.
 */
int
CoordinateComponent::unsetUnit()
{
  mUnit.erase();

  if (mUnit.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "boundaryMin" element of this CoordinateComponent.
 */
const Boundary*
CoordinateComponent::getBoundaryMin() const
{
  return mBoundaryMin;
}


/*
 * Returns the value of the "boundaryMin" element of this CoordinateComponent.
 */
Boundary*
CoordinateComponent::getBoundaryMin()
{
  return mBoundaryMin;
}


/*
 * Returns the value of the "boundaryMax" element of this CoordinateComponent.
 */
const Boundary*
CoordinateComponent::getBoundaryMax() const
{
  return mBoundaryMax;
}


/*
 * Returns the value of the "boundaryMax" element of this CoordinateComponent.
 */
Boundary*
CoordinateComponent::getBoundaryMax()
{
  return mBoundaryMax;
}


/*
 * Predicate returning @c true if this CoordinateComponent's "boundaryMin"
 * element is set.
 */
bool
CoordinateComponent::isSetBoundaryMin() const
{
  return (mBoundaryMin != NULL);
}


/*
 * Predicate returning @c true if this CoordinateComponent's "boundaryMax"
 * element is set.
 */
bool
CoordinateComponent::isSetBoundaryMax() const
{
  return (mBoundaryMax != NULL);
}


/*
 * Sets the value of the "boundaryMin" element of this CoordinateComponent.
 */
int
CoordinateComponent::setBoundaryMin(const Boundary* boundaryMin)
{
  if (mBoundaryMin == boundaryMin)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (boundaryMin == NULL)
  {
    delete mBoundaryMin;
    mBoundaryMin = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mBoundaryMin;
    mBoundaryMin = (boundaryMin != NULL) ? boundaryMin->clone() : NULL;
    if (mBoundaryMin != NULL)
    {
      mBoundaryMin->setElementName("boundaryMin");
      mBoundaryMin->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "boundaryMax" element of this CoordinateComponent.
 */
int
CoordinateComponent::setBoundaryMax(const Boundary* boundaryMax)
{
  if (mBoundaryMax == boundaryMax)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (boundaryMax == NULL)
  {
    delete mBoundaryMax;
    mBoundaryMax = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mBoundaryMax;
    mBoundaryMax = (boundaryMax != NULL) ? boundaryMax->clone() : NULL;
    if (mBoundaryMax != NULL)
    {
      mBoundaryMax->setElementName("boundaryMax");
      mBoundaryMax->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new Boundary object, adds it to this CoordinateComponent object
 * and returns the Boundary object created.
 */
Boundary*
CoordinateComponent::createBoundaryMin()
{
  if (mBoundaryMin != NULL)
  {
    delete mBoundaryMin;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mBoundaryMin = new Boundary(spatialns);

  mBoundaryMin->setElementName("boundaryMin");

  delete spatialns;

  connectToChild();

  return mBoundaryMin;
}


/*
 * Creates a new Boundary object, adds it to this CoordinateComponent object
 * and returns the Boundary object created.
 */
Boundary*
CoordinateComponent::createBoundaryMax()
{
  if (mBoundaryMax != NULL)
  {
    delete mBoundaryMax;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mBoundaryMax = new Boundary(spatialns);

  mBoundaryMax->setElementName("boundaryMax");

  delete spatialns;

  connectToChild();

  return mBoundaryMax;
}


/*
 * Unsets the value of the "boundaryMin" element of this CoordinateComponent.
 */
int
CoordinateComponent::unsetBoundaryMin()
{
  delete mBoundaryMin;
  mBoundaryMin = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "boundaryMax" element of this CoordinateComponent.
 */
int
CoordinateComponent::unsetBoundaryMax()
{
  delete mBoundaryMax;
  mBoundaryMax = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
CoordinateComponent::renameSIdRefs(const std::string& oldid,
                                   const std::string& newid)
{
  if (isSetUnit() && mUnit == oldid)
  {
    setUnit(newid);
  }
}


/*
 * Returns the XML element name of this CoordinateComponent object.
 */
const std::string&
CoordinateComponent::getElementName() const
{
  static const string name = "coordinateComponent";
  return name;
}


/*
 * Returns the libSBML type code for this CoordinateComponent object.
 */
int
CoordinateComponent::getTypeCode() const
{
  return SBML_SPATIAL_COORDINATECOMPONENT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * CoordinateComponent object have been set.
 */
bool
CoordinateComponent::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetType() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * CoordinateComponent object have been set.
 */
bool
CoordinateComponent::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetBoundaryMin() == false)
  {
    allPresent = false;
  }

  if (isSetBoundaryMax() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
CoordinateComponent::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetBoundaryMin() == true)
  {
    mBoundaryMin->write(stream);
  }

  if (isSetBoundaryMax() == true)
  {
    mBoundaryMax->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
CoordinateComponent::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mBoundaryMin != NULL)
  {
    mBoundaryMin->accept(v);
  }

  if (mBoundaryMax != NULL)
  {
    mBoundaryMax->accept(v);
  }

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
CoordinateComponent::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mBoundaryMin != NULL)
  {
    mBoundaryMin->setSBMLDocument(d);
  }

  if (mBoundaryMax != NULL)
  {
    mBoundaryMax->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
CoordinateComponent::connectToChild()
{
  SBase::connectToChild();

  if (mBoundaryMin != NULL)
  {
    mBoundaryMin->connectToParent(this);
  }

  if (mBoundaryMax != NULL)
  {
    mBoundaryMax->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
CoordinateComponent::enablePackageInternal(const std::string& pkgURI,
                                           const std::string& pkgPrefix,
                                           bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetBoundaryMin())
  {
    mBoundaryMin->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetBoundaryMax())
  {
    mBoundaryMax->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
CoordinateComponent::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mBoundaryMin != NULL)
  {
    if (mBoundaryMin->getId() == id)
    {
      return mBoundaryMin;
    }

    obj = mBoundaryMin->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mBoundaryMax != NULL)
  {
    if (mBoundaryMax->getId() == id)
    {
      return mBoundaryMax;
    }

    obj = mBoundaryMax->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
CoordinateComponent::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mBoundaryMin != NULL)
  {
    if (mBoundaryMin->getMetaId() == metaid)
    {
      return mBoundaryMin;
    }

    obj = mBoundaryMin->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mBoundaryMax != NULL)
  {
    if (mBoundaryMax->getMetaId() == metaid)
    {
      return mBoundaryMax;
    }

    obj = mBoundaryMax->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
CoordinateComponent::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mBoundaryMin, filter);
  ADD_FILTERED_POINTER(ret, sublist, mBoundaryMax, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
CoordinateComponent::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());

  if (name == "boundaryMin")
  {
    if (mBoundaryMin != NULL)
    {
      getErrorLog()->logPackageError("spatial",
        SpatialCoordinateComponentAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    mBoundaryMin = new Boundary(spatialns);
    mBoundaryMin->setElementName(name);
    obj = mBoundaryMin;
  }
  else if (name == "boundaryMax")
  {
    if (mBoundaryMax != NULL)
    {
      getErrorLog()->logPackageError("spatial",
        SpatialCoordinateComponentAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    mBoundaryMax = new Boundary(spatialns);
    mBoundaryMax->setElementName(name);
    obj = mBoundaryMax;
  }

  delete spatialns;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
CoordinateComponent::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("type");

  attributes.add("unit");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
CoordinateComponent::readAttributes(const XMLAttributes& attributes,
                                    const ExpectedAttributes&
                                      expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (static_cast<ListOfCoordinateComponents*>(getParentSBMLObject())->size() <
    2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("spatial",
          SpatialGeometryLOCoordinateComponentsAllowedAttributes, pkgVersion,
            level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("spatial",
          SpatialGeometryLOCoordinateComponentsAllowedCoreAttributes, pkgVersion,
            level, version, details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("spatial",
        SpatialCoordinateComponentAllowedAttributes, pkgVersion, level, version,
          details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("spatial",
        SpatialCoordinateComponentAllowedCoreAttributes, pkgVersion, level,
          version, details);
    }
  }

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<CoordinateComponent>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SpatialIdSyntaxRule, level, version, "The id '" + mId + "' does "
        "not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Spatial attribute 'id' is missing from the "
      "<CoordinateComponent> element.";
    log->logPackageError("spatial",
      SpatialCoordinateComponentAllowedAttributes, pkgVersion, level, version,
        message);
  }

  // 
  // type enum (use = "required" )
  // 

  std::string type;
  assigned = attributes.readInto("type", type);

  if (assigned == true)
  {
    if (type.empty() == true)
    {
      logEmptyString(type, level, version, "<CoordinateComponent>");
    }
    else
    {
      mType = CoordinateKind_fromString(type.c_str());

      if (CoordinateKind_isValid(mType) == 0)
      {
        std::string msg = "The type on the <CoordinateComponent> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logPackageError("spatial",
          SpatialCoordinateComponentTypeMustBeCoordinateKindEnum, pkgVersion,
            level, version, msg);
      }
    }
  }
  else
  {
    std::string message = "Spatial attribute 'type' is missing.";
    log->logPackageError("spatial",
      SpatialCoordinateComponentAllowedAttributes, pkgVersion, level, version,
        message);
  }

  // 
  // unit UnitSIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("unit", mUnit);

  if (assigned == true)
  {
    if (mUnit.empty() == true)
    {
      logEmptyString(mUnit, level, version, "<CoordinateComponent>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mUnit) == false)
    {
      logError(SpatialCoordinateComponentUnitMustBeUnitSId, level, version,
        "The attribute unit='" + mUnit + "' does not conform to the syntax.");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
CoordinateComponent::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), CoordinateKind_toString(mType));
  }

  if (isSetUnit() == true)
  {
    stream.writeAttribute("unit", getPrefix(), mUnit);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new CoordinateComponent_t using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 */
LIBSBML_EXTERN
CoordinateComponent_t *
CoordinateComponent_create(unsigned int level,
                           unsigned int version,
                           unsigned int pkgVersion)
{
  return new CoordinateComponent(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this CoordinateComponent_t object.
 */
LIBSBML_EXTERN
CoordinateComponent_t*
CoordinateComponent_clone(const CoordinateComponent_t* cc)
{
  if (cc != NULL)
  {
    return static_cast<CoordinateComponent_t*>(cc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this CoordinateComponent_t object.
 */
LIBSBML_EXTERN
void
CoordinateComponent_free(CoordinateComponent_t* cc)
{
  if (cc != NULL)
  {
    delete cc;
  }
}


/*
 * Returns the value of the "id" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
const char *
CoordinateComponent_getId(const CoordinateComponent_t * cc)
{
  if (cc == NULL)
  {
    return NULL;
  }

  return cc->getId().empty() ? NULL : safe_strdup(cc->getId().c_str());
}


/*
 * Returns the value of the "type" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
CoordinateKind_t
CoordinateComponent_getType(const CoordinateComponent_t * cc)
{
  if (cc == NULL)
  {
    return COORDINATE_KIND_INVALID;
  }

  return cc->getType();
}


/*
 * Returns the value of the "type" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
const char *
CoordinateComponent_getTypeAsString(const CoordinateComponent_t * cc)
{
  return CoordinateKind_toString(cc->getType());
}


/*
 * Returns the value of the "unit" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
const char *
CoordinateComponent_getUnit(const CoordinateComponent_t * cc)
{
  if (cc == NULL)
  {
    return NULL;
  }

  return cc->getUnit().empty() ? NULL : safe_strdup(cc->getUnit().c_str());
}


/*
 * Predicate returning @c 1 if this CoordinateComponent_t's "id" attribute is
 * set.
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetId(const CoordinateComponent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this CoordinateComponent_t's "type" attribute is
 * set.
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetType(const CoordinateComponent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->isSetType()) : 0;
}


/*
 * Predicate returning @c 1 if this CoordinateComponent_t's "unit" attribute is
 * set.
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetUnit(const CoordinateComponent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->isSetUnit()) : 0;
}


/*
 * Sets the value of the "id" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_setId(CoordinateComponent_t * cc, const char * id)
{
  return (cc != NULL) ? cc->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_setType(CoordinateComponent_t * cc, CoordinateKind_t type)
{
  return (cc != NULL) ? cc->setType(type) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_setTypeAsString(CoordinateComponent_t * cc,
                                    const char * type)
{
  return (cc != NULL) ? cc->setType(type): LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "unit" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_setUnit(CoordinateComponent_t * cc, const char * unit)
{
  return (cc != NULL) ? cc->setUnit(unit) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetId(CoordinateComponent_t * cc)
{
  return (cc != NULL) ? cc->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetType(CoordinateComponent_t * cc)
{
  return (cc != NULL) ? cc->unsetType() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "unit" attribute of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetUnit(CoordinateComponent_t * cc)
{
  return (cc != NULL) ? cc->unsetUnit() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "boundaryMin" element of this
 * CoordinateComponent_t.
 */
LIBSBML_EXTERN
const Boundary_t*
CoordinateComponent_getBoundaryMin(const CoordinateComponent_t * cc)
{
  if (cc == NULL)
  {
    return NULL;
  }

  return (Boundary_t*)(cc->getBoundaryMin());
}


/*
 * Returns the value of the "boundaryMax" element of this
 * CoordinateComponent_t.
 */
LIBSBML_EXTERN
const Boundary_t*
CoordinateComponent_getBoundaryMax(const CoordinateComponent_t * cc)
{
  if (cc == NULL)
  {
    return NULL;
  }

  return (Boundary_t*)(cc->getBoundaryMax());
}


/*
 * Predicate returning @c 1 if this CoordinateComponent_t's "boundaryMin"
 * element is set.
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetBoundaryMin(const CoordinateComponent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->isSetBoundaryMin()) : 0;
}


/*
 * Predicate returning @c 1 if this CoordinateComponent_t's "boundaryMax"
 * element is set.
 */
LIBSBML_EXTERN
int
CoordinateComponent_isSetBoundaryMax(const CoordinateComponent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->isSetBoundaryMax()) : 0;
}


/*
 * Sets the value of the "boundaryMin" element of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_setBoundaryMin(CoordinateComponent_t * cc,
                                   const Boundary_t* boundaryMin)
{
  return (cc != NULL) ? cc->setBoundaryMin(boundaryMin) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "boundaryMax" element of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_setBoundaryMax(CoordinateComponent_t * cc,
                                   const Boundary_t* boundaryMax)
{
  return (cc != NULL) ? cc->setBoundaryMax(boundaryMax) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new Boundary_t object, adds it to this CoordinateComponent_t
 * object and returns the Boundary_t object created.
 */
LIBSBML_EXTERN
Boundary_t*
CoordinateComponent_createBoundaryMin(CoordinateComponent_t* cc)
{
  if (cc == NULL)
  {
    return NULL;
  }

  return (Boundary_t*)(cc->createBoundaryMin());
}


/*
 * Creates a new Boundary_t object, adds it to this CoordinateComponent_t
 * object and returns the Boundary_t object created.
 */
LIBSBML_EXTERN
Boundary_t*
CoordinateComponent_createBoundaryMax(CoordinateComponent_t* cc)
{
  if (cc == NULL)
  {
    return NULL;
  }

  return (Boundary_t*)(cc->createBoundaryMax());
}


/*
 * Unsets the value of the "boundaryMin" element of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetBoundaryMin(CoordinateComponent_t * cc)
{
  return (cc != NULL) ? cc->unsetBoundaryMin() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "boundaryMax" element of this CoordinateComponent_t.
 */
LIBSBML_EXTERN
int
CoordinateComponent_unsetBoundaryMax(CoordinateComponent_t * cc)
{
  return (cc != NULL) ? cc->unsetBoundaryMax() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * CoordinateComponent_t object have been set.
 */
LIBSBML_EXTERN
int
CoordinateComponent_hasRequiredAttributes(const CoordinateComponent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * CoordinateComponent_t object have been set.
 */
LIBSBML_EXTERN
int
CoordinateComponent_hasRequiredElements(const CoordinateComponent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


