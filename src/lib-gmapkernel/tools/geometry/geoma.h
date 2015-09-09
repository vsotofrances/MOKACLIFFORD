#line 988 "nw/geoma.nw"
    namespace nklein {
	namespace nklein_priv {
	    
#line 960 "nw/geoma.nw"
template<const unsigned int N>
    class GeomGradeTable {
    private:
	
#line 888 "nw/geoma.nw"
    static int gradeTable[ 1U << (N) ];
#line 964 "nw/geoma.nw"
    protected:
	
#line 907 "nw/geoma.nw"
    GeomGradeTable()
    {
	for ( unsigned ii=0; ii < ( 1U << (N) ); ++ii ) {
	    unsigned int iiBits = 0;
	    
#line 924 "nw/geoma.nw"
    char* ptr = (char*)&ii;

    for ( unsigned int kk=0; kk < sizeof(unsigned int); ++kk ) {
	static const unsigned int lut[] = {
	    0, 1, 1, 2, 1, 2, 2, 3,
	    1, 2, 2, 3, 2, 3, 3, 4
	};
	iiBits += lut[ ( ptr[kk] >> 0 ) & 0x0F ];
	iiBits += lut[ ( ptr[kk] >> 4 ) & 0x0F ];
    }
#line 912 "nw/geoma.nw"
	    gradeTable[ii] = iiBits;
	}
    }
#line 966 "nw/geoma.nw"
    public:
	
#line 944 "nw/geoma.nw"
    static inline unsigned int GetGrade( unsigned int index )
    {
	if ( index >= ( 1U << (N) ) ) {
        throw std::out_of_range( "index" );
	}
	return gradeTable[index];
    }
#line 968 "nw/geoma.nw"
    };
#line 991 "nw/geoma.nw"
	    
#line 859 "nw/geoma.nw"
template<const unsigned int P, const unsigned int Q=0>
    class GeomMultTable : public GeomGradeTable<P+Q> {
    private:
	
#line 738 "nw/geoma.nw"
    static int multTable[ 1U << (P+Q) ][ 1U << (P+Q) ];
#line 863 "nw/geoma.nw"
    protected:
	
#line 760 "nw/geoma.nw"
    GeomMultTable()
    {
	for ( unsigned ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    unsigned int iiInitialTopBits
		= nklein_priv::GeomGradeTable< P+Q >::GetGrade(ii);

	    for ( unsigned jj=0; jj < ( 1U << (P+Q) ); ++jj ) {
		unsigned int iiTopBits = iiInitialTopBits;

		
#line 790 "nw/geoma.nw"
    int sign = 1;

    for ( unsigned int kk=0; kk < (P+Q); ++kk ) {
	unsigned int bit = ( 1U << kk );

	
#line 812 "nw/geoma.nw"
    if ( ( ii & bit ) != 0 ) {
	--iiTopBits;
    }

#line 797 "nw/geoma.nw"
	if ( ( jj & bit ) != 0 ) {
	    sign *= ( iiTopBits & 1 ) ? -1 : 1;

	    if ( ( ii & bit ) != 0 ) {
		
#line 823 "nw/geoma.nw"
    if ( kk >= P ) {
	sign *= -1;
    }
#line 802 "nw/geoma.nw"
	    }
	}
    }

#line 771 "nw/geoma.nw"
		multTable[ii][jj] = sign;
	    }
	}
    }
#line 865 "nw/geoma.nw"
    public:
	
#line 837 "nw/geoma.nw"
    static inline bool IsPositive( unsigned int ii, unsigned int jj )
    {
	if ( ii >= ( 1U << (P+Q) ) ) {
	    throw std::out_of_range( "first index" );
	}
	if ( jj >= ( 1U << (P+Q) ) ) {
	    throw std::out_of_range( "second index" );
	}
	return ( multTable[ii][jj] >= 0 );
    }
#line 867 "nw/geoma.nw"
    };
#line 992 "nw/geoma.nw"
	};

	
// * Inicio clase * //
#line 611 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q=0>
    class GeometricAlgebra
	: public nklein_priv::GeomMultTable<P,Q>
    {
    protected:
	
#line 130 "nw/geoma.nw"
    Type coef[ 1U << (P+Q) ];
#line 617 "nw/geoma.nw"
    public:
	
#line 152 "nw/geoma.nw"
    GeometricAlgebra( bool init = true )
    {
	if ( init ) {
	    for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
		coef[ii] = 0;
	    }
	}
    }
#line 168 "nw/geoma.nw"
    inline
    GeometricAlgebra( const GeometricAlgebra<Type,P,Q>& b )
    {
	*this = b;
    }
#line 182 "nw/geoma.nw"
    inline GeometricAlgebra<Type,P,Q>&
    operator =( const GeometricAlgebra<Type,P,Q>& b )
    {
	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    coef[ii] = b.coef[ii];
	}
	return *this;
    }
#line 200 "nw/geoma.nw"
    inline Type&
    operator [] ( const unsigned int index )
    {
	if ( index >= ( 1U << (P+Q) ) ) {
	    throw std::out_of_range( "index" );
	}
	return coef[ index ];
    }
#line 213 "nw/geoma.nw"
    inline const Type&
    operator [] ( const unsigned int index ) const
    {
	if ( index >= ( 1U << (P+Q) ) ) {
	    throw std::out_of_range( "index" );
	}
	return coef[ index ];
    }
#line 366 "nw/geoma.nw"
    inline
    GeometricAlgebra<Type,P,Q>
    GradeInvolution( void ) const
    {
	GeometricAlgebra<Type,P,Q> a(false);
	Type zero = 0;

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    if ( ( nklein_priv::GeomGradeTable< P+Q >::GetGrade( ii ) & 1 )
	    != 0 ) {
		a[ii] = zero - coef[ii];
	    } else {
		a[ii] = coef[ii];
	    }
	}

	return a;
    }
#line 423 "nw/geoma.nw"
    inline
    GeometricAlgebra<Type,P,Q>
    Reversion( void ) const
    {
	GeometricAlgebra<Type,P,Q> a(false);
	Type zero = 0;

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    if ( ( nklein_priv::GeomGradeTable< P+Q >::GetGrade( ii ) & 2 )
	    != 0 ) {
		a[ii] = zero - coef[ii];
	    } else {
		a[ii] = coef[ii];
	    }
	}

	return a;
    }
#line 453 "nw/geoma.nw"
    inline
    GeometricAlgebra<Type,P,Q>
    Conjugation( void ) const
    {
	GeometricAlgebra<Type,P,Q> a(false);
	Type zero = 0;

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    switch ( nklein_priv::GeomGradeTable< P+Q >::GetGrade( ii ) & 3 ) {
	    case 0:
	    case 3:
		a[ii] = coef[ii];
		break;
	    case 1:
	    case 2:
		a[ii] = zero - coef[ii];
		break;
	    }
	}


	return a;
    }
#line 619 "nw/geoma.nw"
    /** Ampliacion VICTOR */
    inline
    GeometricAlgebra<Type,P,Q>
    Grade( unsigned int kk ) const
    {
    GeometricAlgebra<Type,P,Q> a(true);
    if ( kk > (P+Q) ) {
        throw std::out_of_range( "grade kk" );
    }

    for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
        if (  nklein_priv::GeomGradeTable< P+Q >::GetGrade( ii ) == kk  ) a[ii] = coef[ii];
    }

    return a;
    }

    /** FIN VICTOR*/
    };
#line 995 "nw/geoma.nw"

// * fin clase *//


#line 230 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator + ( const GeometricAlgebra<Type,P,Q>& a,
		    const Type& b )
    {
	GeometricAlgebra<Type,P,Q> c = a;

	c[0] = a[0] + b;

	return c;
    }
#line 247 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator + ( const Type& a,
		    const GeometricAlgebra<Type,P,Q>& b )
    {
	GeometricAlgebra<Type,P,Q> c = b;

	c[0] = a + b[0];

	return c;
    }
#line 266 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator + ( const GeometricAlgebra<Type,P,Q>& a,
		    const GeometricAlgebra<Type,P,Q>& b )
    {
	GeometricAlgebra<Type,P,Q> c(false);

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    c[ii] = a[ii] + b[ii];
	}

	return c;
    }
#line 290 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator - ( const GeometricAlgebra<Type,P,Q>& a,
		    const Type& b )
    {
	GeometricAlgebra<Type,P,Q> c = a;

	c[0] = a[0] - b;

	return c;
    }
#line 314 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator - ( const GeometricAlgebra<Type,P,Q>& a,
		    const GeometricAlgebra<Type,P,Q>& b )
    {
	GeometricAlgebra<Type,P,Q> c(false);

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    c[ii] = a[ii] - b[ii];
	}

	return c;
    }
#line 339 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator - ( const GeometricAlgebra<Type,P,Q>& a )
    {
	GeometricAlgebra<Type,P,Q> b(false);
	Type zero = 0;

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    b[ii] = zero - a[ii];
	}

	return b;
    }
#line 485 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator * ( const GeometricAlgebra<Type,P,Q>& a,
		    const Type& b )
    {
	GeometricAlgebra<Type,P,Q> c;

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    c[ ii ] = a[ ii ] * b;
	}

	return c;
    }
#line 505 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator * ( const Type& a,
		    const GeometricAlgebra<Type,P,Q>& b )
    {
	GeometricAlgebra<Type,P,Q> c;

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    c[ ii ] = a * b[ ii ];
	}

	return c;
    }
#line 533 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator * ( const GeometricAlgebra<Type,P,Q>& a,
		    const GeometricAlgebra<Type,P,Q>& b )
    {
	GeometricAlgebra<Type,P,Q> c;

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    for ( unsigned int jj=0; jj < ( 1U << (P+Q) ); ++jj ) {
		unsigned int index = ( ii ^ jj );
		if ( c.IsPositive( ii, jj ) ) {
		    c[ index ] = c[ index ] + ( a[ ii ] * b[ jj ] );
		} else {
		    c[ index ] = c[ index ] - ( a[ ii ] * b[ jj ] );
		}
	    }
	}

	return c;
    }
#line 571 "nw/geoma.nw"
template <class Type, const unsigned int P, const unsigned int Q>
    inline
    GeometricAlgebra<Type,P,Q>
    operator ^ ( const GeometricAlgebra<Type,P,Q>& a,
		    const GeometricAlgebra<Type,P,Q>& b )
    {
	GeometricAlgebra<Type,P,Q> c;

	for ( unsigned int ii=0; ii < ( 1U << (P+Q) ); ++ii ) {
	    for ( unsigned int jj=0; jj < ( 1U << (P+Q) ); ++jj ) {
		unsigned int mask = ( ii & jj );
		if ( mask == 0 ) {
		    unsigned int index = ( ii ^ jj );
		    if ( c.IsPositive( ii, jj ) ) {
			c[ index ] = c[ index ] + ( a[ ii ] * b[ jj ] );
		    } else {
			c[ index ] = c[ index ] - ( a[ ii ] * b[ jj ] );
		    }
		}
	    }
	}

	return c;
    }
#line 996 "nw/geoma.nw"
/** VICTOR AMPLIACION */

    };
