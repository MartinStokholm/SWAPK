
template<typename T>SharedPtr<T>()
{ 
    public: 
        SharedPtr(T *t);
        SharedPtr(const SharedPtr&);
} 