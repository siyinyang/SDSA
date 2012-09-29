#pragma once
#include <algorithm> // for std::swap
#include <cstddef>
#include <cassert>

// IMatrix traits: This describes how a IMatrix is accessed. By
// externalizing this information into a traits class, the same code
// can be used both with native arrays and IMatrix classes. To use the
// dfault implementation of the traits class, a IMatrix type has to
// provide the following definitions as members:
//
// * typedef ... index_type;
//   - The type used for indexing (e.g. size_t)
// * typedef ... value_type;
//   - The element type of the IMatrix (e.g. double)
// * index_type min_row() const;
//   - returns the minimal allowed row index
// * index_type max_row() const;
//   - returns the maximal allowed row index
// * index_type min_column() const;
//   - returns the minimal allowed column index
// * index_type max_column() const;
//   - returns the maximal allowed column index
// * value_type& operator()(index_type i, index_type k)
//   - returns a reference to the element i,k, where
//     min_row() <= i <= max_row()
//     min_column() <= k <= max_column()
// * value_type operator()(index_type i, index_type k) const
//   - returns the value of element i,k
//
// Note that the functions are all inline and simple, so the compiler
// should completely optimize them away.
template<typename T>
class IMatrix{
    T epsilon;
    int nrows;
    int ncols;
    T** A;
    public:
        typedef std::size_t index_type;
        typedef T value_type;
        IMatrix(T** M, index_type rrows, index_type ncols);
        ~IMatrix(); 
        void swap_rows(index_type i, index_type k);
        void divide_row(index_type i, value_type v);
        void add_multiple_row(index_type i, index_type k, value_type v);
        void to_reduced_row_echelon_form();
        index_type min_row(){ return 0; }
        index_type max_row(){ return nrows-1; }
        index_type min_column(){ return 0; }
        index_type max_column(){ return ncols-1; }
        value_type element(index_type i, index_type k){ return A[i][k]; }
		int rank();
        //value_type& element(index_type i, index_type k){ return A[i][k]; }
};

template<typename T>
IMatrix<T>::IMatrix(T** M, 
                typename IMatrix<T>::index_type _nrows, 
                typename IMatrix<T>::index_type _ncols){
    nrows = _nrows;
    ncols = _ncols;
    A = M;
	
	epsilon = numeric_limits<T>::epsilon();
}

template<typename T>
IMatrix<T>::~IMatrix(){
    for(int i = 0; i < nrows; i++){
        delete[] A[i];
    }
}

template<typename T>
int IMatrix<T>::rank(){
	to_reduced_row_echelon_form();

	int zero_row_counts = 0;
	for(index_type i = min_row(); i <= max_row(); ++i){
		bool is_zero_row = true;
		for(index_type j = min_column(); j <= max_column(); ++j){
			if(abs(A[i][j]) > epsilon){
				is_zero_row = false;
				break;
			}
		}
		if(is_zero_row)
			zero_row_counts++;
	}

	return nrows - zero_row_counts;
}

// Swap rows i and k of a IMatrix A
// Note that due to the reference, both dimensions are preserved for
// built-in arrays
template<typename T>
void IMatrix<T>::swap_rows(
                 typename IMatrix<T>::index_type i,
                 typename IMatrix<T>::index_type k)
{
  
  // check indices
  assert(min_row() <= i);
  assert(i <= max_row());
 
  assert(min_row() <= k);
  assert(k <= max_row());
 
  for (index_type col = min_column(); col <= max_column(); ++col)
    std::swap(A[i][col], A[k][col]);
}
 
// divide row i of IMatrix A by v
template<typename T>
 void IMatrix<T>::divide_row(
                  typename IMatrix<T>::index_type i,
                  typename IMatrix<T>::value_type v)
{
  typedef typename IMatrix<T>::index_type index_type;
 
  assert(min_row() <= i);
  assert(i <= max_row());
 
  assert(v != 0);
 
  for (index_type col = min_column(); col <= max_column(); ++col)
    A[i][col] /= v;
}
 
// in IMatrix A, add v times row k to row i
template<typename T>
 void IMatrix<T>::add_multiple_row(
                  typename IMatrix<T>::index_type i,
                  typename IMatrix<T>::index_type k,
                  typename IMatrix<T>::value_type v)
{
  
  typedef typename IMatrix<T>::index_type index_type;
 
  assert(min_row() <= i);
  assert(i <= max_row());
 
  assert(min_row() <= k);
  assert(k <= max_row());
 
  for (index_type col = min_column(); col <= max_column(); ++col)
    A[i][col] += v * A[k][col];
}
 
// convert A to reduced row echelon form
template<typename T>
void IMatrix<T>::to_reduced_row_echelon_form()
{
 
  typedef typename IMatrix<T>::index_type index_type;
 
  index_type lead = min_row();
 
  for (index_type row = min_row(); row <= max_row(); ++row)
  {
    
    if (lead > max_column())
      return;
    index_type i = row;
    while (A[i][lead] == 0)
    {   
      ++i;
      if (i > max_row())
      {
        i = row;
        ++lead;
        if (lead > max_column())
          return;
      }
    }
    swap_rows( i, row);
    divide_row( row, A[row][lead]);
    for (i = min_row(); i <= max_row(); ++i)
    {
      if (i != row)
        add_multiple_row( i, row, -A[i][lead]);
    }
  }
}

