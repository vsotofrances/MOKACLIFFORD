//******************************************************************************
#include "multivector.h"
//******************************************************************************
#include INCLUDE_NON_INLINE("multivector.icc")
//******************************************************************************

//******************************************************************************
//INLINE
//CMultivector::CMultivector(const CDart *dart,bool ComputePlane)
//{
//    nklein::GeometricAlgebra< double, 4 > Q;
//    CDart *nextdart;
//    CAttributeVertex *attVertex;

//    /** Initialize */
//    MD=0;
//    Ih[e0|e1|e2|e3]=1;

//    /** pto inicial y final */
//    attVertex=(CAttributeVertex*) dart->getAttribute(ORBIT_VERTEX, ATTRIBUTE_VERTEX);

//    P[e0]=1.0;
//    P[e1]=attVertex->getX();
//    P[e2]=attVertex->getY();
//    P[e3]=attVertex->getZ();
//    PD=P*Ih;
//    MD.Grade(3)=PD;//!< point

//    nextdart=dart->getAlpha0();
//    attVertex=(CAttributeVertex*) nextdart->getAttribute(ORBIT_VERTEX, ATTRIBUTE_VERTEX);
//    Q[e0]=1.0;
//    Q[e1]=attVertex->getX();
//    Q[e2]=attVertex->getY();
//    Q[e3]=attVertex->getZ();

//    L=P^Q;
//    LD=L*Ih;
//    MD.Grade(2)=LD;//!< line

//    /** plano si se indica */
//    if(ComputePlane)
//        Plane(dart);

//}
////******************************************************************************
//INLINE
//void CMultivector::Plane(const CDart *dart)
//{
//    nklein::GeometricAlgebra< double, 4 > pto[2];
//    CAttributeVertex *attVertex;
//    CDart *nextdart=dart;

//    do
//    {

//        nextdart=nextdart->getAlpha0();
//    }while(nextdart!=dart)
//}
