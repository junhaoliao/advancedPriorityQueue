#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>



template <typename T>
void printVector (const std::vector<T>& myVector){
    for(unsigned i = 0 ; i < myVector.size(); i++){
        std::cout<<myVector[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename T> //tested
bool priorityQueue_empty(std::vector<T> &myVector){
    return myVector.empty();
}

template <typename T> //tested
void priorityQueue_pop(std::vector<T> &myVector){
    std::pop_heap(myVector.begin(), myVector.end());
    myVector.pop_back();
}

template <typename T> // tested
void priorityQueue_popN(std::vector<T> &myVector, const unsigned& N){
    std::sort_heap(myVector.begin(),myVector.end());
    myVector.erase(myVector.end()-N-1,myVector.end()-N);
    std::reverse(myVector.begin(),myVector.end());
}

template <typename T> // tested
void priorityQueue_push(std::vector<T> &myVector, const T& toBePushed){
    myVector.push_back(toBePushed);
    std::push_heap(myVector.begin(), myVector.end());
}

template <typename T> // tested
const T& priorityQueue_top(const std::vector<T> &myVector){
    return myVector.front();
}

template <typename T> // 0 is the toppest
const T& priorityQueue_topN(std::vector<T> &myVector,const unsigned& N){
    std::sort_heap(myVector.begin(),myVector.end());
    std::reverse(myVector.begin(),myVector.end());
    return myVector[N];
}

template <typename T>
void priorityQueue_update(std::vector<T> &myVector){
    std::make_heap(myVector.begin(),myVector.end());
}

template <typename T>
void priorityQueue_forceUpdate(std::vector<T> &myVector){
    std::sort_heap(myVector.begin(),myVector.end());
    std::reverse(myVector.begin(),myVector.end());
}

int main() {

    std::vector<double> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::make_heap(numbers.begin(), numbers.end());

    for(unsigned i = 0 ; i < numbers.size(); i++){
        std::cout<<numbers[i]<<" ";
    }
    std::cout<<std::endl;

    std::priority_queue<unsigned> myQueue;

    for(unsigned i = 0 ; i < numbers.size(); i++){
        myQueue.push(numbers[i]);
    }

    std::cout<<myQueue.top()<<std::endl;

    std::cout << "Hello, World!" << std::endl;

    std::vector<unsigned> testVect;

    for(unsigned i = 0 ; i < numbers.size(); i++){
        priorityQueue_push<unsigned>(testVect,numbers[i]);
    }

    printVector<unsigned>(testVect);

    // testing push and top
    std::cout<<std::endl;
    priorityQueue_push<unsigned>(testVect,1000);
    printVector<unsigned>(testVect);
    std::cout<<"The top is"<<" "<<priorityQueue_top(testVect)<<std::endl;

    std::cout<<std::endl;
    priorityQueue_push<unsigned>(testVect,10000);
    printVector<unsigned>(testVect);
    std::cout<<"The top is"<<" "<<priorityQueue_top(testVect)<<std::endl;

//    // testing force update
//    std::cout<<std::endl;
//    priorityQueue_forceUpdate<unsigned>(testVect);
//    printVector<unsigned>(testVect);

    std::cout<<std::endl;
    priorityQueue_push<unsigned>(testVect,10);
    printVector<unsigned>(testVect);
    std::cout<<"The top is"<<" "<<priorityQueue_top(testVect)<<std::endl;

    //testing pop
    std::cout<<std::endl;
    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);

    std::cout<<std::endl;
    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);

    // testing pop1(removed second toppest),pop2(removed third toppest)
    std::cout<<"testing pop1(removed 2nd toppest),pop2(removed 3rd toppest)"<<std::endl;
    std::cout<<std::endl;
    priorityQueue_popN<unsigned>(testVect,1);
    printVector<unsigned>(testVect);

    std::cout<<std::endl;
    priorityQueue_popN<unsigned>(testVect,2);
    printVector<unsigned>(testVect);

    std::cout<<std::endl;
    priorityQueue_push<unsigned>(testVect,7);
    priorityQueue_popN<unsigned>(testVect,2);
    printVector<unsigned>(testVect);

    // testing force update
    std::cout<<std::endl;
        priorityQueue_forceUpdate<unsigned>(testVect);
    printVector<unsigned>(testVect);


//testing topN
    std::cout<<std::endl;
    std::cout<<"testing top1(2nd toppest),top2(3rd toppest)"<<std::endl;
    std::cout<<"The top1 is"<<" "<<priorityQueue_topN<unsigned>(testVect,1)<<std::endl;
    std::cout<<"The top2 is"<<" "<<priorityQueue_topN<unsigned>(testVect,2)<<std::endl;
    std::cout<<"The top3 is"<<" "<<priorityQueue_topN<unsigned>(testVect,3)<<std::endl;
    std::cout<<"The top4 is"<<" "<<priorityQueue_topN<unsigned>(testVect,4)<<std::endl;
    printVector<unsigned>(testVect);

    std::cout<<std::endl;
    priorityQueue_popN<unsigned>(testVect,8);
    printVector<unsigned>(testVect);

    priorityQueue_popN<unsigned>(testVect,100); // corner case. dont care for now
    printVector<unsigned>(testVect);

//    priorityQueue_update<unsigned>(testVect);
//    printVector<unsigned>(testVect);


// final
    std::cout<<std::endl;
    std::cout<<"The top is"<<" "<<priorityQueue_top(testVect)<<std::endl;
    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);

    std::cout<<std::endl;
    std::cout<<"The pQueue is "<<(priorityQueue_empty<unsigned>(testVect)?"":"not ")<<"empty"<<std::endl;

    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);

    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);

    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);

    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);

    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);

    std::cout<<"The pQueue is "<<(priorityQueue_empty<unsigned>(testVect)?"":"not ")<<"empty"<<std::endl;

    priorityQueue_pop<unsigned>(testVect);
    printVector<unsigned>(testVect);
    std::cout<<"The pQueue is "<<(priorityQueue_empty<unsigned>(testVect)?"":"not ")<<"empty"<<std::endl;
    return 0;
}