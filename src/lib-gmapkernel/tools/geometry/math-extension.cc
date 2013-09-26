/*
 * lib-gmapkernel : Un noyau de 3-G-cartes et des opérations.
 * Copyright (C) 2004, Moka Team, Université de Poitiers, Laboratoire SIC
 *               http://www.sic.sp2mi.univ-poitiers.fr/
 * Copyright (C) 2009, Guillaume Damiand, CNRS, LIRIS,
 *               guillaume.damiand@liris.cnrs.fr, http://liris.cnrs.fr/
 *
 * This file is part of lib-gmapkernel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//******************************************************************************
#include "math-extension.hh"
#include "vertex.hh"
//******************************************************************************
const TCoordinate EPSILON = 1E-4;
//******************************************************************************
TCoordinate det(const CVertex & ALine1, const CVertex & ALine2,
		const CVertex & ALine3)
{
  return
    ALine1.getX()*(ALine2.getY()*ALine3.getZ() - ALine2.getZ()*ALine3.getY()) -
    ALine1.getY()*(ALine2.getX()*ALine3.getZ() - ALine2.getZ()*ALine3.getX()) +
    ALine1.getZ()*(ALine2.getX()*ALine3.getY() - ALine2.getY()*ALine3.getX());
}
//******************************************************************************
