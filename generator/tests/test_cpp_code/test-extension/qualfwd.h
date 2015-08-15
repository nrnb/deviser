/**
 * @file: qualfwd.h
 * @brief: Definition of qualfwd.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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


#ifndef qualfwd_H__
#define qualfwd_H__


#ifdef __cplusplus
# define CLASS_OR_STRUCT class
#else
# define CLASS_OR_STRUCT struct
#endif /* __cplusplus */


LIBSBML_CPP_NAMESPACE_BEGIN


typedef CLASS_OR_STRUCT QualitativeSpecies QualitativeSpecies_t
typedef CLASS_OR_STRUCT Transition         Transition_t
typedef CLASS_OR_STRUCT Input              Input_t
typedef CLASS_OR_STRUCT Output             Output_t
typedef CLASS_OR_STRUCT DefaultTerm        DefaultTerm_t
typedef CLASS_OR_STRUCT FunctionTerm       FunctionTerm_t


LIBSBML_CPP_NAMESPACE_END


#undef CLASS_OR_STRUCT


#endif /* !qualfwd_H__ */

