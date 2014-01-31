/* Atributo multivector
 *
 *
 */
//******************************************************************************
#ifndef MULTIVECTOR_H
#define MULTIVECTOR_H
//******************************************************************************
#include <stdexcept>   //! VICTOR
#include "geoma.h"     //! VICTOR
#include "geomaData.h" //! VICTOR
#include "vertex.hh"
#include "dart.hh"
#include "attribute-vertex.hh"
#include "inline-macro.hh"
//******************************************************************************
enum {
    E0 = 0,
    E1 = ( 1 << 0 ),
    E2 = ( 1 << 1 ),
    E3 = ( 1 << 2 )
}; // R3
enum{
    e0 = ( 1 << 0 ),
    e1 = ( 1 << 1 ),
    e2 = ( 1 << 2 ),
    e3 = ( 1 << 3 )
}; // R4

using namespace GMap3d;

class CMultivector
{
private:
    nklein::GeometricAlgebra< double, 4 > MD; //homogeneus model
    double l,a,v; //! length,area,volume
public:
    /** Get */
    nklein::GeometricAlgebra< double, 4 > getMD() const;
    double getL() const {return l;};
    double getA() const {return a;};
    double getV() const {return v;};
    /** Set */
    void setMD(nklein::GeometricAlgebra< double, 4 > MVector);
public:
    /** constructores */
    CMultivector();

    CMultivector(const CMultivector &AMv);

    /** Construye a partir de un dart de una cara
     *
     ***************************************************/
    CMultivector(const CDart *,CVertex *AVertex=NULL);

private:
    double computeLAV(void);
    nklein::GeometricAlgebra<double, 4 >  getPoint(const CDart * dart);

};
//******************************************************************************
//#include INCLUDE_INLINE("multivector.icc")
//******************************************************************************
#endif // MULTIVECTOR_H
//******************************************************************************
