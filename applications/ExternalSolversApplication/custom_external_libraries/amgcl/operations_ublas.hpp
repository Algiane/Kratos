#ifndef AMGCL_OPERATIONS_UBLAS_HPP
#define AMGCL_OPERATIONS_UBLAS_HPP

/*
The MIT License

Copyright (c) 2012 Denis Demidov <ddemidov@ksu.ru>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/**
 * \file   operations_ublas.hpp
 * \author Denis Demidov <ddemidov@ksu.ru>
 * \brief  Adaptors for Boost.uBlas types.
 */

#include <amgcl/common.hpp>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/operation_sparse.hpp>
#include <boost/numeric/ublas/operation.hpp>

#include <boost/typeof/typeof.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_arithmetic.hpp>

namespace amgcl {

/// Returns value type for an ublas vector.
/** Necessary for ublas types to work with amgcl::solve() functions. */
template <typename T>
struct value_type<boost::numeric::ublas::vector<T> >
{
    typedef T type;
};

/// Returns inner product of two ublas vectors.
/** Necessary for ublas types to work with amgcl::solve() functions. */
template <typename T1, typename T2>
T1 inner_prod(const boost::numeric::ublas::vector<T1> &x,
              const boost::numeric::ublas::vector<T2> &y
        )
{
    int size = x.size();
    double value = 0.0;
    #pragma omp parallel for reduction(+:value) firstprivate(size) shared(x,y)
    for(int i=0; i<size; i++)
      value += x[i]*y[i];
    return value;
//      return boost::numeric::ublas::inner_prod(x, y);
}

/// Returns norm of an ublas vector.
/** Necessary for ublas types to work with amgcl::solve() functions. */
template <typename T>
T norm(const boost::numeric::ublas::vector<T> &x) {
    int size = x.size();
    double value = 0.0;
    #pragma omp parallel for reduction(+:value) firstprivate(size) shared(x)
    for(int i=0; i<size; i++)
      value += x[i]*x[i];
    return sqrt(value);
//      return boost::numeric::ublas::norm_2(x);
}

/// Clears (sets elements to zero) an ublas vector.
/** Necessary for ublas types to work with amgcl::solve() functions. */
template <typename T>
void clear(boost::numeric::ublas::vector<T> &x) {
    int size = x.size();
    #pragma omp parallel for firstprivate(size)
    for(int i=0; i<size; i++)
      x[i] = 0.0;
//      x.clear();
}


namespace sparse {

/// Maps ublas compressed matrix to format supported by amgcl.
/** No data is copied here. */
template <class T>
matrix_map<T, ptrdiff_t>
map(const boost::numeric::ublas::compressed_matrix<T, boost::numeric::ublas::row_major> &A) {
    return matrix_map<T, ptrdiff_t>(
            A.size1(),
            A.size2(),
            // amgcl expects signed type for row and col data. This should work
            // for decently sized matrices:
            reinterpret_cast<const ptrdiff_t*>(A.index1_data().begin()),
            reinterpret_cast<const ptrdiff_t*>(A.index2_data().begin()),
            A.value_data().begin()
            );
}

} // namespace sparse

/// Specialization of residual operation for ublas types.
/** Necessary for ublas types to work with amgcl::solve() functions. */
template <typename real>
void residual(
        const boost::numeric::ublas::compressed_matrix<real, boost::numeric::ublas::row_major> &A,
        const boost::numeric::ublas::vector<real> &x,
        const boost::numeric::ublas::vector<real> &f,
        boost::numeric::ublas::vector<real> &y
        )
{
    const size_t n = A.size1();

    BOOST_AUTO(Arow, A.index1_data().begin());
    BOOST_AUTO(Acol, A.index2_data().begin());
    BOOST_AUTO(Aval, A.value_data().begin());

#pragma omp parallel for schedule(dynamic, 1024)
    for(size_t i = 0; i < n; ++i) {
        real buf = f[i];
        for(size_t j = Arow[i], e = Arow[i + 1]; j < e; ++j)
            buf -= Aval[j] * x[Acol[j]];
        y[i] = buf;
    }
}

/// Specialization of matrix-vector product for ublas types.
/** Necessary for ublas types to work with amgcl::solve() functions. */
template <typename real>
void axpy(
        const boost::numeric::ublas::compressed_matrix<real, boost::numeric::ublas::row_major> &A,
        const boost::numeric::ublas::vector<real> &x,
        boost::numeric::ublas::vector<real> &y
        )
{
    const size_t n = A.size1();

    BOOST_AUTO(Arow, A.index1_data().begin());
    BOOST_AUTO(Acol, A.index2_data().begin());
    BOOST_AUTO(Aval, A.value_data().begin());

#pragma omp parallel for schedule(dynamic, 1024)
    for(size_t i = 0; i < n; ++i) {
        real buf = 0;
        for(size_t j = Arow[i], e = Arow[i + 1]; j < e; ++j)
            buf += Aval[j] * x[Acol[j]];
        y[i] = buf;
    }
}

} // namespace amgcl

#endif
