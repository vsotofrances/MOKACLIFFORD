/* Atributo multivector
 *
 *
 */
//******************************************************************************
#ifndef MVECTORR4_H
#define MVECTORR4_H
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

class CMVectorR4
{
private:
    nklein::GeometricAlgebra< double, 4 > M; //homogeneus model
    nklein::GeometricAlgebra< double, 4 > P ,L ,A ; //homogeneus model
    nklein::GeometricAlgebra< double, 4 > PD,LD,AD; //homogeneus dual model
    nklein::GeometricAlgebra< double, 4 > Ih; // pseudoescalar homogeneus model
public:

public:
    /** constructores */
    CMVectorR4(const CDart *);

private:
    void Plane(const CDart *dart);
};
//******************************************************************************
#include INCLUDE_INLINE("mvectorR4.icc")
//******************************************************************************
#endif // MVECTORR4_H
//******************************************************************************
