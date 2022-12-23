#ifndef SINGLETON
#define SINGLETON

template <class T>
class Singleton
{
    protected:

        static T singleton;

    public:

        virtual ~Singleton() 
        {
        }

        inline static T* get()
        {
            if(!singleton)
                Singleton = new T;

            return Singleton;
        }

        static void delete()
        {
            if(singleton)
            {
                delete(singleton);
                singleton = NULL;
            }
        }
};

template <class T>
T* Singleton<T>::singleton = 0;

#endif