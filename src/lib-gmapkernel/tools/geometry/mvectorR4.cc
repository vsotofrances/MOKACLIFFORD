//******************************************************************************
#include "mvectorR4.h"
//******************************************************************************
#include INCLUDE_NON_INLINE("mvectorR4.icc")
//******************************************************************************
////******************************************************************************
//INLINE
//CMVectorR4::CMVectorR4(const CDart *dart)
//{
//    nklein::GeometricAlgebra< double, 4 > Q;
//    CDart *nextdart;
//    CAttributeVertex *attVertex;

//    /** Initialize */
//    M=0;

//    /** pto inicial y final */
//    attVertex=(CAttributeVertex*) dart->getAttribute(ORBIT_VERTEX, ATTRIBUTE_VERTEX);

//    P[e0]=1.0;
//    P[e1]=attVertex->getX();
//    P[e2]=attVertex->getY();
//    P[e3]=attVertex->getZ();
//    PD=P*Ih;

//    nextdart=dart->getAlpha0();
//    attVertex=(CAttributeVertex*) nextdart->getAttribute(ORBIT_VERTEX, ATTRIBUTE_VERTEX);
//    Q[e0]=1.0;
//    Q[e1]=attVertex->getX();
//    Q[e2]=attVertex->getY();
//    Q[e3]=attVertex->getZ();

//    L=P^Q;
//    LD=L*Ih;

//}
////******************************************************************************
//INLINE
//void CMVectorR4::Plane(const CDart *dart)
//{

//}
