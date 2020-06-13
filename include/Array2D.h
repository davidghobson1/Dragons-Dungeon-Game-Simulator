#ifndef ARRAY2D_H
#define ARRAY2D_H

/*****************************************************
 * Array2D Class
A Template Collection Class representing a 2-dimensional
array of class T objects
Class supports a getElement, setElement, and print function.
It performs basic bounds checking and throws exceptions if
bounds are exceded
T objects are stored in a dynamically allocated array of fixed
size, which cannot be changed
******************************************************/

template <class T>
class Array2D
{
  public:
    Array2D(int=29,int=7);
    ~Array2D();
    int getXDimension() const;
    int getYDimension() const;
    T& getElement(int, int) const;
    void setElement(T, int, int);
    void print() const;

  private:
    T** head;
    int xdim;
    int ydim;
};

template <class T>
Array2D<T>::Array2D(int x, int y)
{
  xdim = x;
  ydim = y;

  head = new T*[ydim];

  for(int i = 0; i < ydim; i++){
    head[i] = new T[xdim];
  }
}

template <class T>
Array2D<T>::~Array2D()
{
  for(int i = 0; i < ydim; i++){
    delete [] head[i];
  }

  delete [] head;
}

template <class T>
int Array2D<T>::getXDimension() const {  return xdim;  }

template <class T>
int Array2D<T>::getYDimension() const {  return ydim;  }

template <class T>
T& Array2D<T>::getElement(int x, int y) const
{
  if(x < 0 || x >= xdim){
    //throw exception
    throw "x dimension out of bounds!";
  }else if(y < 0 || y >= ydim){
    //throw exception
    throw "y dimension out of bounds!";
  }

  return head[y][x];
}

template <class T>
void Array2D<T>::setElement(T t, int x, int y)
{
  if(x < 0 || x >= xdim){
    //throw exception
    throw "x dimension out of bounds!";
  }else if(y < 0 || y >= ydim){
    //throw exception
    throw "y dimension out of bounds!";
  }

  head[y][x] = t;
}

template <class T>
void Array2D<T>::print() const
{
  for(int j = 0; j < ydim; j++){
    for(int i = 0; i < xdim; i++){
      cout << getElement(i, j);
    }
    cout << endl;
  }
}

#endif
