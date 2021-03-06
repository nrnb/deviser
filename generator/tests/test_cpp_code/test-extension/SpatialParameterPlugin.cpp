/**
 * @file SpatialParameterPlugin.cpp
 * @brief Implementation of the SpatialParameterPlugin class.
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
#include <sbml/packages/spatial/extension/SpatialParameterPlugin.h>
#include <sbml/packages/spatial/validator/SpatialSBMLError.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SpatialParameterPlugin using the given uri, prefix and package
 * namespace.
 */
SpatialParameterPlugin::SpatialParameterPlugin(const std::string& uri,
                                               const std::string& prefix,
                                               SpatialPkgNamespaces* spatialns)
  : SBasePlugin(uri, prefix, spatialns)
  , mSpatialSymbolReference (NULL)
  , mAdvectionCoefficient (NULL)
  , mBoundaryCondition (NULL)
  , mDiffusionCoefficient (NULL)
{
  connectToChild();
}


/*
 * Copy constructor for SpatialParameterPlugin.
 */
SpatialParameterPlugin::SpatialParameterPlugin(const SpatialParameterPlugin&
  orig)
  : SBasePlugin( orig )
  , mSpatialSymbolReference ( NULL )
  , mAdvectionCoefficient ( NULL )
  , mBoundaryCondition ( NULL )
  , mDiffusionCoefficient ( NULL )
{
  if (orig.mSpatialSymbolReference != NULL)
  {
    mSpatialSymbolReference = orig.mSpatialSymbolReference->clone();
  }

  if (orig.mAdvectionCoefficient != NULL)
  {
    mAdvectionCoefficient = orig.mAdvectionCoefficient->clone();
  }

  if (orig.mBoundaryCondition != NULL)
  {
    mBoundaryCondition = orig.mBoundaryCondition->clone();
  }

  if (orig.mDiffusionCoefficient != NULL)
  {
    mDiffusionCoefficient = orig.mDiffusionCoefficient->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SpatialParameterPlugin.
 */
SpatialParameterPlugin&
SpatialParameterPlugin::operator=(const SpatialParameterPlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    delete mSpatialSymbolReference;
    if (rhs.mSpatialSymbolReference != NULL)
    {
      mSpatialSymbolReference = rhs.mSpatialSymbolReference->clone();
    }
    else
    {
      mSpatialSymbolReference = NULL;
    }

    delete mAdvectionCoefficient;
    if (rhs.mAdvectionCoefficient != NULL)
    {
      mAdvectionCoefficient = rhs.mAdvectionCoefficient->clone();
    }
    else
    {
      mAdvectionCoefficient = NULL;
    }

    delete mBoundaryCondition;
    if (rhs.mBoundaryCondition != NULL)
    {
      mBoundaryCondition = rhs.mBoundaryCondition->clone();
    }
    else
    {
      mBoundaryCondition = NULL;
    }

    delete mDiffusionCoefficient;
    if (rhs.mDiffusionCoefficient != NULL)
    {
      mDiffusionCoefficient = rhs.mDiffusionCoefficient->clone();
    }
    else
    {
      mDiffusionCoefficient = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SpatialParameterPlugin object.
 */
SpatialParameterPlugin*
SpatialParameterPlugin::clone() const
{
  return new SpatialParameterPlugin(*this);
}


/*
 * Destructor for SpatialParameterPlugin.
 */
SpatialParameterPlugin::~SpatialParameterPlugin()
{
  delete mSpatialSymbolReference;
  mSpatialSymbolReference = NULL;
  delete mAdvectionCoefficient;
  mAdvectionCoefficient = NULL;
  delete mBoundaryCondition;
  mBoundaryCondition = NULL;
  delete mDiffusionCoefficient;
  mDiffusionCoefficient = NULL;
}


/*
 * Returns the value of the "spatialSymbolReference" element of this
 * SpatialParameterPlugin.
 */
const SpatialSymbolReference*
SpatialParameterPlugin::getSpatialSymbolReference() const
{
  return mSpatialSymbolReference;
}


/*
 * Returns the value of the "spatialSymbolReference" element of this
 * SpatialParameterPlugin.
 */
SpatialSymbolReference*
SpatialParameterPlugin::getSpatialSymbolReference()
{
  return mSpatialSymbolReference;
}


/*
 * Returns the value of the "advectionCoefficient" element of this
 * SpatialParameterPlugin.
 */
const AdvectionCoefficient*
SpatialParameterPlugin::getAdvectionCoefficient() const
{
  return mAdvectionCoefficient;
}


/*
 * Returns the value of the "advectionCoefficient" element of this
 * SpatialParameterPlugin.
 */
AdvectionCoefficient*
SpatialParameterPlugin::getAdvectionCoefficient()
{
  return mAdvectionCoefficient;
}


/*
 * Returns the value of the "boundaryCondition" element of this
 * SpatialParameterPlugin.
 */
const BoundaryCondition*
SpatialParameterPlugin::getBoundaryCondition() const
{
  return mBoundaryCondition;
}


/*
 * Returns the value of the "boundaryCondition" element of this
 * SpatialParameterPlugin.
 */
BoundaryCondition*
SpatialParameterPlugin::getBoundaryCondition()
{
  return mBoundaryCondition;
}


/*
 * Returns the value of the "diffusionCoefficient" element of this
 * SpatialParameterPlugin.
 */
const DiffusionCoefficient*
SpatialParameterPlugin::getDiffusionCoefficient() const
{
  return mDiffusionCoefficient;
}


/*
 * Returns the value of the "diffusionCoefficient" element of this
 * SpatialParameterPlugin.
 */
DiffusionCoefficient*
SpatialParameterPlugin::getDiffusionCoefficient()
{
  return mDiffusionCoefficient;
}


/*
 * Predicate returning @c true if this SpatialParameterPlugin's
 * "spatialSymbolReference" element is set.
 */
bool
SpatialParameterPlugin::isSetSpatialSymbolReference() const
{
  return (mSpatialSymbolReference != NULL);
}


/*
 * Predicate returning @c true if this SpatialParameterPlugin's
 * "advectionCoefficient" element is set.
 */
bool
SpatialParameterPlugin::isSetAdvectionCoefficient() const
{
  return (mAdvectionCoefficient != NULL);
}


/*
 * Predicate returning @c true if this SpatialParameterPlugin's
 * "boundaryCondition" element is set.
 */
bool
SpatialParameterPlugin::isSetBoundaryCondition() const
{
  return (mBoundaryCondition != NULL);
}


/*
 * Predicate returning @c true if this SpatialParameterPlugin's
 * "diffusionCoefficient" element is set.
 */
bool
SpatialParameterPlugin::isSetDiffusionCoefficient() const
{
  return (mDiffusionCoefficient != NULL);
}


/*
 * Sets the value of the "spatialSymbolReference" element of this
 * SpatialParameterPlugin.
 */
int
SpatialParameterPlugin::setSpatialSymbolReference(const SpatialSymbolReference*
  spatialSymbolReference)
{
  if (spatialSymbolReference == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (spatialSymbolReference->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != spatialSymbolReference->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != spatialSymbolReference->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != spatialSymbolReference->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mSpatialSymbolReference;
    mSpatialSymbolReference =
      static_cast<SpatialSymbolReference*>(spatialSymbolReference->clone());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "advectionCoefficient" element of this
 * SpatialParameterPlugin.
 */
int
SpatialParameterPlugin::setAdvectionCoefficient(const AdvectionCoefficient*
  advectionCoefficient)
{
  if (advectionCoefficient == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (advectionCoefficient->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != advectionCoefficient->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != advectionCoefficient->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != advectionCoefficient->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mAdvectionCoefficient;
    mAdvectionCoefficient =
      static_cast<AdvectionCoefficient*>(advectionCoefficient->clone());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "boundaryCondition" element of this
 * SpatialParameterPlugin.
 */
int
SpatialParameterPlugin::setBoundaryCondition(const BoundaryCondition*
  boundaryCondition)
{
  if (boundaryCondition == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (boundaryCondition->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != boundaryCondition->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != boundaryCondition->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != boundaryCondition->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mBoundaryCondition;
    mBoundaryCondition =
      static_cast<BoundaryCondition*>(boundaryCondition->clone());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "diffusionCoefficient" element of this
 * SpatialParameterPlugin.
 */
int
SpatialParameterPlugin::setDiffusionCoefficient(const DiffusionCoefficient*
  diffusionCoefficient)
{
  if (diffusionCoefficient == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (diffusionCoefficient->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != diffusionCoefficient->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != diffusionCoefficient->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != diffusionCoefficient->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mDiffusionCoefficient;
    mDiffusionCoefficient =
      static_cast<DiffusionCoefficient*>(diffusionCoefficient->clone());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SpatialSymbolReference object, adds it to this
 * SpatialParameterPlugin object and returns the SpatialSymbolReference object
 * created.
 */
SpatialSymbolReference*
SpatialParameterPlugin::createSpatialSymbolReference()
{
  if (mSpatialSymbolReference != NULL)
  {
    delete mSpatialSymbolReference;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mSpatialSymbolReference = new SpatialSymbolReference(spatialns);

  mSpatialSymbolReference->setSBMLDocument(this->getSBMLDocument());

  delete spatialns;

  connectToChild();

  return mSpatialSymbolReference;
}


/*
 * Creates a new AdvectionCoefficient object, adds it to this
 * SpatialParameterPlugin object and returns the AdvectionCoefficient object
 * created.
 */
AdvectionCoefficient*
SpatialParameterPlugin::createAdvectionCoefficient()
{
  if (mAdvectionCoefficient != NULL)
  {
    delete mAdvectionCoefficient;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mAdvectionCoefficient = new AdvectionCoefficient(spatialns);

  mAdvectionCoefficient->setSBMLDocument(this->getSBMLDocument());

  delete spatialns;

  connectToChild();

  return mAdvectionCoefficient;
}


/*
 * Creates a new BoundaryCondition object, adds it to this
 * SpatialParameterPlugin object and returns the BoundaryCondition object
 * created.
 */
BoundaryCondition*
SpatialParameterPlugin::createBoundaryCondition()
{
  if (mBoundaryCondition != NULL)
  {
    delete mBoundaryCondition;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mBoundaryCondition = new BoundaryCondition(spatialns);

  mBoundaryCondition->setSBMLDocument(this->getSBMLDocument());

  delete spatialns;

  connectToChild();

  return mBoundaryCondition;
}


/*
 * Creates a new DiffusionCoefficient object, adds it to this
 * SpatialParameterPlugin object and returns the DiffusionCoefficient object
 * created.
 */
DiffusionCoefficient*
SpatialParameterPlugin::createDiffusionCoefficient()
{
  if (mDiffusionCoefficient != NULL)
  {
    delete mDiffusionCoefficient;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mDiffusionCoefficient = new DiffusionCoefficient(spatialns);

  mDiffusionCoefficient->setSBMLDocument(this->getSBMLDocument());

  delete spatialns;

  connectToChild();

  return mDiffusionCoefficient;
}


/*
 * Unsets the value of the "spatialSymbolReference" element of this
 * SpatialParameterPlugin.
 */
int
SpatialParameterPlugin::unsetSpatialSymbolReference()
{
  delete mSpatialSymbolReference;
  mSpatialSymbolReference = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "advectionCoefficient" element of this
 * SpatialParameterPlugin.
 */
int
SpatialParameterPlugin::unsetAdvectionCoefficient()
{
  delete mAdvectionCoefficient;
  mAdvectionCoefficient = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "boundaryCondition" element of this
 * SpatialParameterPlugin.
 */
int
SpatialParameterPlugin::unsetBoundaryCondition()
{
  delete mBoundaryCondition;
  mBoundaryCondition = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "diffusionCoefficient" element of this
 * SpatialParameterPlugin.
 */
int
SpatialParameterPlugin::unsetDiffusionCoefficient()
{
  delete mDiffusionCoefficient;
  mDiffusionCoefficient = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SpatialParameterPlugin object have been set.
 */
bool
SpatialParameterPlugin::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
SpatialParameterPlugin::writeElements(XMLOutputStream& stream) const
{
  if (isSetSpatialSymbolReference() == true)
  {
    mSpatialSymbolReference->write(stream);
  }

  if (isSetAdvectionCoefficient() == true)
  {
    mAdvectionCoefficient->write(stream);
  }

  if (isSetBoundaryCondition() == true)
  {
    mBoundaryCondition->write(stream);
  }

  if (isSetDiffusionCoefficient() == true)
  {
    mDiffusionCoefficient->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
SpatialParameterPlugin::accept(SBMLVisitor& v) const
{
  const Parameter* p = static_cast<const
    Parameter*>(this->getParentSBMLObject());
  v.visit(*p);
  v.leave(*p);

  if (mSpatialSymbolReference != NULL)
  {
    mSpatialSymbolReference->accept(v);
  }

  if (mAdvectionCoefficient != NULL)
  {
    mAdvectionCoefficient->accept(v);
  }

  if (mBoundaryCondition != NULL)
  {
    mBoundaryCondition->accept(v);
  }

  if (mDiffusionCoefficient != NULL)
  {
    mDiffusionCoefficient->accept(v);
  }

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
SpatialParameterPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  if (mSpatialSymbolReference != NULL)
  {
    mSpatialSymbolReference->setSBMLDocument(d);
  }

  if (mAdvectionCoefficient != NULL)
  {
    mAdvectionCoefficient->setSBMLDocument(d);
  }

  if (mBoundaryCondition != NULL)
  {
    mBoundaryCondition->setSBMLDocument(d);
  }

  if (mDiffusionCoefficient != NULL)
  {
    mDiffusionCoefficient->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
SpatialParameterPlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
SpatialParameterPlugin::connectToParent(SBase* base)
{
  SBasePlugin::connectToParent(base);

  if (mSpatialSymbolReference != NULL)
  {
    mSpatialSymbolReference->connectToParent(base);
  }

  if (mAdvectionCoefficient != NULL)
  {
    mAdvectionCoefficient->connectToParent(base);
  }

  if (mBoundaryCondition != NULL)
  {
    mBoundaryCondition->connectToParent(base);
  }

  if (mDiffusionCoefficient != NULL)
  {
    mDiffusionCoefficient->connectToParent(base);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
SpatialParameterPlugin::enablePackageInternal(const std::string& pkgURI,
                                              const std::string& pkgPrefix,
                                              bool flag)
{
  if (isSetSpatialSymbolReference())
  {
    mSpatialSymbolReference->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetAdvectionCoefficient())
  {
    mAdvectionCoefficient->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetBoundaryCondition())
  {
    mBoundaryCondition->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetDiffusionCoefficient())
  {
    mDiffusionCoefficient->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
SpatialParameterPlugin::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mSpatialSymbolReference != NULL)
  {
    if (mSpatialSymbolReference->getId() == id)
    {
      return mSpatialSymbolReference;
    }

    obj = mSpatialSymbolReference->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mAdvectionCoefficient != NULL)
  {
    if (mAdvectionCoefficient->getId() == id)
    {
      return mAdvectionCoefficient;
    }

    obj = mAdvectionCoefficient->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mBoundaryCondition != NULL)
  {
    if (mBoundaryCondition->getId() == id)
    {
      return mBoundaryCondition;
    }

    obj = mBoundaryCondition->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mDiffusionCoefficient != NULL)
  {
    if (mDiffusionCoefficient->getId() == id)
    {
      return mDiffusionCoefficient;
    }

    obj = mDiffusionCoefficient->getElementBySId(id);
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
SpatialParameterPlugin::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mSpatialSymbolReference != NULL)
  {
    if (mSpatialSymbolReference->getMetaId() == metaid)
    {
      return mSpatialSymbolReference;
    }

    obj = mSpatialSymbolReference->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mAdvectionCoefficient != NULL)
  {
    if (mAdvectionCoefficient->getMetaId() == metaid)
    {
      return mAdvectionCoefficient;
    }

    obj = mAdvectionCoefficient->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mBoundaryCondition != NULL)
  {
    if (mBoundaryCondition->getMetaId() == metaid)
    {
      return mBoundaryCondition;
    }

    obj = mBoundaryCondition->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mDiffusionCoefficient != NULL)
  {
    if (mDiffusionCoefficient->getMetaId() == metaid)
    {
      return mDiffusionCoefficient;
    }

    obj = mDiffusionCoefficient->getElementByMetaId(metaid);
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
SpatialParameterPlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mSpatialSymbolReference, filter);
  ADD_FILTERED_POINTER(ret, sublist, mAdvectionCoefficient, filter);
  ADD_FILTERED_POINTER(ret, sublist, mBoundaryCondition, filter);
  ADD_FILTERED_POINTER(ret, sublist, mDiffusionCoefficient, filter);


  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
SpatialParameterPlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const SpatialParameterPlugin* plug = static_cast<const
    SpatialParameterPlugin*>(model->getPlugin(getPrefix()));

  if (plug == NULL)
  {
    return ret;
  }

  Model* parent = static_cast<Model*>(getParentSBMLObject());

  if (parent == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  return ret;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
SpatialParameterPlugin::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();
  const XMLNamespaces& xmlns = stream.peek().getNamespaces();
  const std::string& prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ?
    xmlns.getPrefix(mURI) : mPrefix;

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());

  if (prefix == targetPrefix)
  {
    if (name == "spatialSymbolReference")
    {
      if (mSpatialSymbolReference != NULL)
      {
        getErrorLog()->logPackageError("spatial",
          SpatialParameterAllowedElements, getPackageVersion(), getLevel(),
            getVersion());
      }

      mSpatialSymbolReference = new SpatialSymbolReference(spatialns);
      obj = mSpatialSymbolReference;
    }
    else if (name == "advectionCoefficient")
    {
      if (mAdvectionCoefficient != NULL)
      {
        getErrorLog()->logPackageError("spatial",
          SpatialParameterAllowedElements, getPackageVersion(), getLevel(),
            getVersion());
      }

      mAdvectionCoefficient = new AdvectionCoefficient(spatialns);
      obj = mAdvectionCoefficient;
    }
    else if (name == "boundaryCondition")
    {
      if (mBoundaryCondition != NULL)
      {
        getErrorLog()->logPackageError("spatial",
          SpatialParameterAllowedElements, getPackageVersion(), getLevel(),
            getVersion());
      }

      mBoundaryCondition = new BoundaryCondition(spatialns);
      obj = mBoundaryCondition;
    }
    else if (name == "diffusionCoefficient")
    {
      if (mDiffusionCoefficient != NULL)
      {
        getErrorLog()->logPackageError("spatial",
          SpatialParameterAllowedElements, getPackageVersion(), getLevel(),
            getVersion());
      }

      mDiffusionCoefficient = new DiffusionCoefficient(spatialns);
      obj = mDiffusionCoefficient;
    }
  }

  delete spatialns;

  connectToChild();

  return obj;
}

/** @endcond */


/* 
 * @return true, if either the spatial symbol reference, diffusion coefficient, 
 *   advection coefficient or boundary is set. Otherwise the return value is false.
 */ 
bool 
SpatialParameterPlugin::isSpatialParameter() const
{
  return getType() != -1;
}

/* 
 * Determines the type of the spatial parameter, that is one of: 
 * 
 * SBML_SPATIAL_SPATIALSYMBOLREFERENCE
 * SBML_SPATIAL_DIFFUSIONCOEFFICIENT
 * SBML_SPATIAL_ADVECTIONCOEFFICIENT
 * SBML_SPATIAL_BOUNDARYCONDITION
 * 
 * or -1 in case no other is defined.
 */
int 
SpatialParameterPlugin::getType() const
{
  if (isSetSpatialSymbolReference())
  {
    return SBML_SPATIAL_SPATIALSYMBOLREFERENCE;
  }
  if (isSetDiffusionCoefficient())
  {
    return SBML_SPATIAL_DIFFUSIONCOEFFICIENT;
  }    
  if (isSetAdvectionCoefficient())
  {
    return SBML_SPATIAL_ADVECTIONCOEFFICIENT;
  }    
  if (isSetBoundaryCondition())
  {
    return SBML_SPATIAL_BOUNDARYCONDITION;
  }    
  return -1;
}


#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


