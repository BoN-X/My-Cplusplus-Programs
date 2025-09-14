template<typename T>
class shared_ptr {
public:
//constructor
shared_ptr(T* ptr = nullptr) : m_ptr(ptr), m_refCount(new int(1)) {}

//copy constructor
shared_ptr(const shared_ptr& other) : m_ptr(other.m_ptr), m_refCount(other.m_refCount) {
    //increase the reference count
    (*m_refCount)++;
}

//destructor
~shared_ptr() {
    //decrease the reference count
    (*m_refCount)--;
    //if the reference count is zero, delete the pointer
    if (*m_refCount == 0) {
        delete m_ptr;
        delete m_refCount;
    }
}

//overload operator=()
shared_ptr& operator=(const shared_ptr& other) {
    //check self-assignment
    if (this != &other) {
        //decrease the reference count for the old pointer
        (*m_refCount)--;
        //if the reference count is zero, delete the pointer
        if (*m_refCount == 0) {
            delete m_ptr;
            delete m_refCount;
        }
        //copy the data and reference pointer and increase the reference count
        m_ptr = other.m_ptr;
        m_refCount = other.m_refCount;
        //increase the reference count
        (*m_refCount)++;
    }
    return *this;
}

private:
    T* m_ptr;              //points to the actual data
    int* m_refCount;       //reference count
};