//******************************************************************************
#include "multivector.h"
//******************************************************************************
//#include INCLUDE_NON_INLINE("multivector.icc")
//******************************************************************************

//INLINE
CMultivector::CMultivector(const nklein::GeometricAlgebra< double, 4 > & AMv)
{
  MD=AMv;
}

CMultivector::CMultivector(const CDart *dart,CVertex *AVertex)
{
    nklein::GeometricAlgebra< double, 4 > Q;
    CDart *nextdart;

    /** Initialize */
    MD=0;
    Ih[e0|e1|e2|e3]=1;
    refdart=dart;

    /** pto inicial y final */

    P=getPoint(dart);
    PD=P*Ih;
    MD.Grade(3)=PD;//!< dual point

    nextdart=dart->getAlpha0();
    Q=getPoint(nextdart);

    L=P^Q;
    LD=L*Ih;
    MD.Grade(2)=LD;//!< dual line

   /** Baricentre */
   B[e0]=1.0;
   B[e1]=AVertex->getX();
   B[e2]=AVertex->getY();
   B[e3]=AVertex->getZ();

   //if(AVertex != NULL)
   //     Sense(dart);
}

/** Compute sense of the face according to the First Dart given
 *
 ******************************************************************************/
//INLINE
int CMultivector::getSense(const CDart *dart)
{
    const CDart *nextdart;
    nklein::GeometricAlgebra<double, 4 > Point[2];
    int count=0;

    /** compute sense*/
    nextdart=dart;
    do
    {
        Point[0]=getPoint(nextdart);
        Point[1]=getPoint(nextdart->getAlpha0());
        A=B^Point[0]^Point[1];
        AD=AD+A*Ih;
        ++count;

        nextdart=nextdart->getAlpha0()->getAlpha1();

    }while(nextdart!=dart);
    AD=AD*(1./(double) count); //! dual del plano medio respecto al baricentro
    if(AD[e0]>0)
        return 1;
    else
        return -1;
}

//INLINE
nklein::GeometricAlgebra<double, 4 > CMultivector::getPoint(const CDart * dart)
{
    nklein::GeometricAlgebra<double, 4 > Point;
    CAttributeVertex *attVertex;

    attVertex=(CAttributeVertex*) dart->getAttribute(ORBIT_VERTEX, ATTRIBUTE_VERTEX);
    Point[e0]=1.0;
    Point[e1]=attVertex->getX();
    Point[e2]=attVertex->getY();
    Point[e3]=attVertex->getZ();

    return Point;
}
