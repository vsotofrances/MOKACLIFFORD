#line 1012 "nw/geoma.nw"
    namespace nklein {
	namespace nklein_priv {
	    
#line 741 "nw/geoma.nw"
    template<const unsigned int P, const unsigned int Q>
	    int GeomMultTable< P, Q >::multTable[ 1U << (P+Q) ][ 1U << (P+Q) ];
#line 1015 "nw/geoma.nw"
	    
#line 892 "nw/geoma.nw"
    template<const unsigned int N>
	    int GeomGradeTable<N>::gradeTable[ 1U << (N) ];
#line 1016 "nw/geoma.nw"
	};

	static const char* GeometricAlgebraVersion
	    = "nklein::GeometricAlgebra::version: " 
#line 21 "nw/hdr.nw"
"v1.2.2007.08.20"
#line 1019 "nw/geoma.nw"
                                                        ;
    };
