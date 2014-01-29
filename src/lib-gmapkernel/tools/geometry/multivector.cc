//******************************************************************************
#include "multivector.h"
//******************************************************************************
//#include INCLUDE_NON_INLINE("multivector.icc")
//******************************************************************************
//INLINE
CMultivector::CMultivector()
{
}
//INLINE
CMultivector::CMultivector(const CMultivector & AMv)
{
  MD=AMv.getMD();
}
//INLINE
CMultivector::CMultivector(const CDart *dart,CVertex *AVertex)
{

}

/** Compute sense of the face according to the First Dart given
 *
 */
//******************************************************************************
//INLINE
int CMultivector::getSense(const CDart *dart)
{

}
//******************************************************************************
//INLINE
nklein::GeometricAlgebra<double, 4 > CMultivector::getPoint(const CDart * dart)
{

}
//******************************************************************************
//INLINE
nklein::GeometricAlgebra< double, 4 > CMultivector::getMD() const
{
    return MD;
}
//******************************************************************************
//INLINE
void CMultivector::setMD(nklein::GeometricAlgebra< double, 4 >  MVector)
{
    MD=MVector;
}
