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
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(std::string n, const char* ptr) : value(ptr), name(n) //1
    {}
    //2
    const char* value;
    //3 
    std::string name;
};

struct Compare                             //4
{
    T* compare(T* a, T* b) //5
    {
        if( a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if (a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float num1 { 0.0f }, num2 { 0.0f };
    float someStaticFunctionCopy(float* floatPtr)      //12
    {
        if (floatPtr != nullptr)
        {
            std::cout << "U's num1 value: " << num1 << std::endl;
            num1 = *floatPtr;
            std::cout << "U's num1 updated value: " << num1 << std::endl;
            while( std::abs(num2 - num1) > 0.001f )
            {
                num2 += .1f;
            }
            std::cout << "U's num2 updated value: " << num2 << std::endl;
            return num2 * num1;
        }
        return 0.0f;
    }
};

struct Static
{
    static float someStaticFunction(U* that, float* floatPtr)        //10
    {
        if (that != nullptr && floatPtr != nullptr)
        {
            std::cout << "U's num1 value: " << that->num1 << std::endl;
            that->num1 = *floatPtr;
            std::cout << "U's num1 updated value: " << that->num1 << std::endl;
            while( std::abs(that->num2 - that->num1) > 0.001f )
            {
            /*
             write something that makes the distance between that->num2 and that->num1 get smaller
             */
                that->num2 += .1f;
            }
            std::cout << "U's num2 updated value: " << that->num2 << std::endl;
            return that->num2 * that->num1;
        }
        return 0.0f;
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
    T t1("Jack", nullptr);                                             //6
    T t2("Jill", nullptr);                                             //6
    
    Compare f;                                            //7
    auto* smaller = f.compare(&t1, &t2);                              //8
    if (smaller != nullptr)
        std::cout << "the smaller one is " << smaller->name << std::endl; //9
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Static::someStaticFunction(&u1, &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.someStaticFunctionCopy(&updatedValue) << std::endl;
}

        
        
        
        
        
        
        
