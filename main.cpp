/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    int value = 0;
    std::string name = {};
    T(int v, const char* n) : value(v), name(n) { }
     //1
    //2
    //3
};

struct Widget                                //4
{
    T* compare(T* a, T* b) //5
    {
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr;
    }
};

struct U
{
    float uFloatie1 { 0 }, uFloatie2 { 0 };
    float unsharedFunc(float* updateValue)      //12
    {
        if (updateValue != nullptr)
        {
            std::cout << "U's uFloatie1 value: " << this->uFloatie1 << std::endl;
            this->uFloatie1 = *updateValue;
            std::cout << "U's uFloatie1 updated value: " << this->uFloatie1 << std::endl;
            while( std::abs(this->uFloatie2 - this->uFloatie1) > 0.001f )
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                this->uFloatie2 += 1.f;
            }
            std::cout << "U's uFloatie2's updated value: " << this->uFloatie2 << std::endl;
            return this->uFloatie2 * this->uFloatie1;
        }
        return 0.f;            // not sure about this one
    }
};

struct TwoStruct
{
    static float sharedFunc(U* that, float* updateValue )        //10
    {
        if (that != nullptr && updateValue != nullptr)
        {
            std::cout << "U's uFloatie1 value: " << that->uFloatie1 << std::endl;
            that->uFloatie1 = *updateValue;
            std::cout << "U's uFloatie1 updated value: " << that->uFloatie1 << std::endl;
            while( std::abs(that->uFloatie2 - that->uFloatie1) > 0.001f )
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                that->uFloatie2 += 1.f;
            }
            std::cout << "U's uFloatie2's updated value: " << that->uFloatie2 << std::endl;
            return that->uFloatie2 * that->uFloatie1;
        }
        return 0.f;            // not sure about this one
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    const char* queue = "q";
    const char* pee = "p";
    T test1(2, queue);                                             //6
    T test2(3, pee);                                             //6
    
    Widget f;                                            //7
    auto* smaller = f.compare(&test1, &test2);                              //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is " << smaller->name << std::endl; //10
    }
    else
    {
        std::cout << "Comparison returned null. Possible Reasons include:\n";
        std::cout << "1. Both items for comparison are the same value and neither is smaller.\n";
        std::cout << "2. One or both items are not comparible.\n";
    }
    
    U yu;
    //U* yuPtr = nullptr;
    float updatedValue = 5.f;
    std::cout << "[static func] yu's multiplied values: " << TwoStruct::sharedFunc( &yu , &updatedValue ) << std::endl;                  //11
    U ewe;
    std::cout << "[member func] ewe's multiplied values: " << ewe.unsharedFunc( &updatedValue ) << std::endl;
}
