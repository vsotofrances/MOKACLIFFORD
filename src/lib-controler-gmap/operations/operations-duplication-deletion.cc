/*
 * lib-controler-gmap : Le contrôleur de 3-G-cartes, surcouche de lib-controler.
 * Copyright (C) 2004, Moka Team, Université de Poitiers, Laboratoire SIC
 *               http://www.sic.sp2mi.univ-poitiers.fr/
 * Copyright (C) 2009, Guillaume Damiand, CNRS, LIRIS,
 *               guillaume.damiand@liris.cnrs.fr, http://liris.cnrs.fr/
 *
 * This file is part of lib-controler-gmap
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
#include "g-map-vertex.hh"
#include "controler-gmap.hh"
#include <cassert>

using namespace GMap3d;
//******************************************************************************
bool CControlerGMap::deleteSelection()
{
  bool res = false;
  
  if (canApplyOperation(COperation(OPERATION_DELETE_DARTS)))
    {
      undoRedoPreSave();

      int nb = FMap->deleteMarkedDarts(getSelectionMark());

      assert(isMapOk());
	    
      if (nb==0)
	{
	  setMessage("No dart removed");
	  undoRedoPostSaveFailed();
	}
      else
	{
	  undoRedoPostSaveOk();
	  unsetLastSelectedDart();

	  setModelChanged();
	  res = true;
	
	  setMessage(nb, (nb==1 ? " dart removed" : " darts removed"));
	}
    }

  return res;

}
//******************************************************************************
bool CControlerGMap::duplicateSelection()
{
  bool res = false;
  
  if (canApplyOperation(COperation(OPERATION_DUPLICATE_DARTS)))
    {
      undoRedoPreSave();

      int nb= FMap->duplicateMarkedDarts(getSelectionMark());

      assert(isMapOk());
      
      if (nb==0)
	{
	  setMessage("No dart duplicated");
	  undoRedoPostSaveFailed();
	}
      else
	{
	  undoRedoPostSaveOk();
	  setModelChanged();
	  setMessage(nb, (nb==1 ? " dart duplicated" : " darts duplicated"));
	  res = true;
	}
    }

  return res;
}
//******************************************************************************
