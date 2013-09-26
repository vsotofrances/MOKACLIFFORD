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
// Ce fichier fait partie de "g-map-vertex.hh".
//******************************************************************************

public:

/**
 * Calcule le dual en dimension ADim d'un ensemble de brins.
 * À chaque cellule C de dimension ADim de l'objet initial est associé un
 * sommet S placé sur le barycentre de C.
 *
 * @param ADim La dimension dans laquelle le dual est calculé
 * @param AMarkNumber Un numéro de marque
 * @return Le nombre de brins dupliqués
 *
 * @precondition (ADim == 2) || (ADim == 3)
 */
int dualOfMarkedDarts(int ADim, int AMarkNumber);

//******************************************************************************
