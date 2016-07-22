#ifndef DARRAY_H
#define DARRAY_H

#include <iostream.h>

#include <string.h>
#include <stdlib.h>
const int ReSize = 1;

template <class Type>
class Array;

template <class Type>
class TypeRep{
friend class Array<Type>;
private:
	TypeRep(){_active = 0;}
	TypeRep(int newSize, int delta) {
		if (newSize > 0)
		{
			_size = newSize;
			_active = 0;
			sizeChange = delta;
			rep = new Type [_size];
			if(rep == NULL)
         	throw "Insufficient memory to resize";
		}
		else
		{
			_size = newSize;
			_active = 0;
			sizeChange = delta;
			rep = NULL;
		}
		count = 1;
	}
	~TypeRep() {if (rep)delete [] rep;}
	TypeRep* copy();
	Type *rep;
	int _size;
	int _active;
	int sizeChange;
	int count;
};



template <class Type>
TypeRep<Type>* TypeRep<Type>::copy()
{
	TypeRep<Type> *r = new TypeRep<Type>(_size,sizeChange);
	if(r==NULL)
		throw "Insufficient memory to create a copy";
	for(int i=0; i<_size;i++)
		r->rep[i] = rep[i];
	r->_active = _active;
	return r;
}


template <class Type>
class Array
{
public:
	Array(int = 0,int = ReSize);
	Array(int,int,Type);
	Array(const Array&);
	~Array();
	Type& operator [](int);
	Type operator [](int)const;
	Array& operator = (const Array&);
	Array copy();//makes a copy that will not allow destruction of original
	int size()const {return data->_size;}// how much memory is allocated for array
	int numberInArray()const {return data->_active;}//how many active items in array
	int operator ==(const Array &)const;
	int operator != (const Array &a)const{return !(*this == a);}
	void operator += (const Array&);
	// concatenates array at end of current array

	// data related functions
	int find(const Type &)const;
	// find returns -1 if not found and subscript if found
	// find uses == for Type so make sure to override ==
	// properly
	int insertItem(const Type &);
	// inserts the item at the end of the list
	int insertItemAt(const Type &,int);
	// inserts at the place indicated by second parameter
	void deleteItem(const Type &);
	// locates item Type and deletes if it is found
	Type deleteItemAt(int);
	// deletes item at the indicated location
	void clearArray();
	// empties the array
protected:
	int reSize(int);
	Type& sub(int i);
	Type sub(int i)const;
private:
	TypeRep<Type> *data;
};
template <class Type>
Array<Type>::Array(int newSize, int delta)
{
  data = new TypeRep<Type>(newSize,delta);
  if(data == NULL)
	throw "Insufficient memory to create a new array";
}

template <class Type>
Array<Type>::Array(int newSize, int delta, Type val)
{
	data = new TypeRep<Type> (newSize,delta);
  if(data == NULL)
  	throw "Insufficient memory to create a new array";
	for(int i = 0;i<data->_size;i++)
		data->rep[i] = val;
}


template <class Type>
Array<Type>::Array(const Array<Type> &x)
{
	data = x.data;
	data->count++;
}

template <class Type>
Array<Type>& Array<Type>::operator = (const Array<Type> &s)
{
	s.data->count++;
	if (--data->count ==0)
		delete data;
	data = s.data;
	return *this;
}

template <class Type>
Array<Type> Array<Type>::copy()
{
	Array<Type> result;
	result.data = data->copy();
	return result;
}

template <class Type>
Array<Type>::~Array()
{
	if (--data->count ==0)
		delete data;
}

template <class Type>
Type Array<Type>::operator[](int i)const
{
	return sub(i);
}

template <class Type>
Type Array<Type>::sub(int i)const
{
	if(i>=0 && i< data->_size)
		return data->rep[i];
	else
	{
		char buff[255];
		char buff1[255];
		itoa(i,buff1,10);
		strcpy(buff,"Subscript ");
		strcat(buff,buff1);
		strcat(buff," out of range");
		throw buff;
   }
}

template <class Type>
Type& Array<Type>::operator [] (int i)
{
	return sub(i);
}

template <class Type>
Type& Array<Type>::sub(int i)
{
	if (i < 0)
	{
		char buff[255];
		char buff1[255];
		itoa(i,buff1,10);
		strcpy(buff,"Subscript ");
		strcat(buff,buff1);
		strcat(buff," out of range");
		throw buff;
	}
	else if ((i >= data->_size)&&(data->sizeChange>0))
		reSize(i);
	else if (i>=data->_size)
	{
		char buff[255];
		char buff1[255];
		itoa(i,buff1,10);
		strcpy(buff,"Subscript ");
		strcat(buff,buff1);
		strcat(buff," out of range and this array cannot be resized");
		throw buff;
	}
	return data->rep[i];
}


template <class Type>
int Array<Type>::operator ==(const Array<Type> &a)const
{
	if (data->_active!= a.data->_active)
		return 0;
	for(int sub = 0; sub<data->_active;sub++)
		if (!(data->rep[sub] == a[sub]))
			return 0;
	return 1;
}


template <class Type>
int Array<Type>::reSize(int i)
{
	int increase = ((i - data->_size)/data->sizeChange + 1)*data->sizeChange;
	int tsize = data->_size + increase;
	TypeRep<Type> *temp = new TypeRep<Type> (tsize,data->sizeChange);
	if(temp == NULL)
		throw "Insufficient memory to resize this array";
	if (data)
	{
		for (int j = 0; j < data->_size; j++)
			temp->rep[j] = data->rep[j];
		temp->_active = data->_active;
	}
	if (--data->count == 0)
		delete data;
	data = temp;
	return 1;
}

template <class Type>
void Array<Type>::operator += (const Array<Type> &a)
{
	int newSize = data->_active + a.data->_active;

		if(newSize>0)
		{
			TypeRep<Type> *tdata = new TypeRep<Type> (newSize,data->sizeChange);
			if(tdata == NULL)
				throw "Insufficient memory to add onto this array";
			for(int i = 0;i<data->_active;i++)
				tdata->rep[i] = data->rep[i];
			for(i = 0; i<a.data->_active;i++)
				tdata->rep[data->_size + i] = a.data->rep[i];
			if(--data->count ==0)
				delete data;
			data = tdata;
			data->_active += a.data->_active;
		}
}


template <class Type>
int Array<Type>::find(const Type &t)const
{
	for(int i = 0;i<data->_active;i++)
		if (t == sub(i))
			return i;
	return -1;//non subsrcipt value
}

template <class Type>
int Array<Type>::insertItem(const Type &t)
{
	sub(data->_active)=t;
	return data->_active++;
}

template <class Type>
int Array<Type>::insertItemAt(const Type &t,int loc)
{
	if (loc <0 || loc > data->_active)
		throw "Cannot insert at this location.";
    for(int i = data->_active-1;i>=loc;i--)
        sub(i+1) = sub(i);
	sub(loc) = t;
	data->_active++;
	return loc;
}

template <class Type>
void Array<Type>::deleteItem(const Type &t)
{
	int loc = find(t);
	if (loc >=0 && loc < data->_active)
		deleteItemAt(loc);
	else
		throw "Item was not found in the array";
}

template <class Type>
Type Array<Type>::deleteItemAt(int loc)
{
	if (loc <0 || loc >= data->_active)
		throw "Cannot delete at this location since it is not currently active";
	Type value;
	value = sub(loc);
	for (int i = loc;i< data->_active-1;i++)
		sub(i) = sub(i+1);
    data->_active--;
	return value;
}
template <class Type>
void Array<Type>::clearArray()
{
	data->_active = 0;
}


// This purely virtual class is intended to provide a functor
// so that traversals of the array may process the array using
// this functor

template <class Type>
class ArrayProcess
{
public:
	ArrayProcess(){}
	virtual void process(int,Type &)=0;
};

template <class Type>
class ArrayIterator
{
public:
	ArrayIterator(Array<Type> &t):array(t){init();}
	void init(){_loc = 0;}
	int operator ++(){return _loc++;}
	int operator ++(int){return _loc++;}
	Type operator ()()const{return array[_loc];}
   Type& operator()(){return array[_loc];}
	operator int(){return _loc < array.numberInArray();}
	void traverse(ArrayProcess<Type> *);//for simple traversal operations such as print
private:
	Array<Type> &array;
	int _loc;
};


template <class Type>
void ArrayIterator<Type>::traverse(ArrayProcess<Type> *p)
{
	for (int i = 0; i< array.numberInArray();i++)
		p->process(i,array[i]);
}

#endif
