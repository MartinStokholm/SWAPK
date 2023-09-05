
template<typename T>SharedPtr()
{ 
    public: 
        SharedPtr(T *t);
        SharedPtr(const SharedPtr&);
        operator=(const SharedPtr&):SharedPtr&;
        ~SharedPtr();
        operator->(): T*{query();};
        operator*(): T&{query();};
        count(): size_t {query();};
} 