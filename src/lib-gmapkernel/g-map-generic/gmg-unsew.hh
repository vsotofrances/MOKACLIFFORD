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
// Ce fichier est une partie de "gmap-generic.hh".
//******************************************************************************

public:

/**
 * Découd selon la dimension ADim tous les brins de la cartes marqués avec
 * la marque numéro AMarkNumber.
 *
 * @param AMarkNumber Un numéro de marque
 * @param ADim Une dimension
 * @return Le nombre de décousures effectuées
 */
int unsewMarkedCells(int AMarkNumber, int ADim);

/**
 * Découd tous les brins de la carte marqués, en déterminant de manière
 * automatique la dimension de chacune des décousures.
 *
 * @param AMarkNumber Un numéro de marque
 * @return Le nombre de décousures effectuées
 */
int intuitiveUnsewMarkedCells(int AMarkNumber);

//******************************************************************************
