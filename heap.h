#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap_vec;
  int m; //aryness
  PComparator c;
  void heapify(int index);



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
:m(m), c(c) {

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  heap_vec.push_back(item);
	if (heap_vec.size() == 1) {//no need to sort
		return;
	}
	//trickle up item
	int index = heap_vec.size()-1;//position of the last item
	int parent = (index-1)/m; //parent position
	while (index > 0 && c(heap_vec[index], heap_vec[parent])) {
		T temp = heap_vec[index];//swap
    heap_vec[index] = heap_vec[parent];
    heap_vec[parent] = temp;
		index = parent;//update positions
		parent = (index-1)/m;
	}
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Error: top() empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	else {
		return heap_vec[0];
	}

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Error: pop() empty");

  }
	else {
		heap_vec[0] = heap_vec[heap_vec.size() - 1];//swap top and back
		heap_vec.pop_back();
		//trickle down the new top
		heapify(0);
		return;
	}


}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return heap_vec.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return heap_vec.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int idx){
	int size_ = heap_vec.size();
  if ((idx*m+2) > size_) {//leaf node
		return;
	}
	else {//find best
		int best = m*idx+1;
		for (int i=2; i<=m; i++) {//loop to find best
			int curr = idx*m+i;
			if (curr <= size_) {//exist
				if(c(heap_vec[curr],heap_vec[best])) {//better than current
        	best = curr;//update best
      	}
			}
		}
		if (c(heap_vec[best], heap_vec[idx])) {//check with parent
      T temp = heap_vec[idx];//swap parent and child
      heap_vec[idx] = heap_vec[best];
      heap_vec[best] = temp;
      heapify(best);//heapify on new parent
    }
	}
}

#endif

