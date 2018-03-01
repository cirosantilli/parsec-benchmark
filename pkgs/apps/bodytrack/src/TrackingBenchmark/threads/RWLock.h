// (C) Copyright Christian Bienia 2007
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0.
//
//  file : RWLock.h
//  author : Christian Bienia - cbienia@cs.princeton.edu
//  description : A read-write lock

#ifndef RWLOCK_H
#define RWLOCK_H

#if defined(HAVE_CONFIG_H)
# include "config.h"
#endif

#include <pthread.h>
#include <exception>

#include "LockTypes.h"


namespace threads {

//General rwlock exception
class RWLockException: public std::exception {
  public:
    virtual const char *what() const noexcept {return "Unspecified rwlock error";}
};

//RWLock initialization error
class RWLockInitException: public RWLockException {
  public:
    virtual const char *what() const noexcept {return "Unspecified error while initializing rwlock";}
};

//RWLock destruction error
class RWLockDestroyException: public RWLockException {
  public:
    virtual const char *what() const noexcept {return "Unspecified error while destroying rwlock";}
};

//Resources exhausted
class RWLockResourceException: public RWLockException {
  public:
    virtual const char *what() const noexcept {return "Insufficient resources";}
};

//General locking error
class RWLockLockingException: public RWLockException {
  public:
    virtual const char *what() const noexcept {return "Unspecified locking error";}
};

//Deadlock detected
class RWLockDeadlockException: public RWLockLockingException {
  public:
    virtual const char *what() const noexcept {return "Deadlock detected";}
};

//Unknown error
class RWLockUnknownException: public RWLockException {
  public:
    virtual const char *what() const noexcept {return "Unknown error";}
};

//A standard rwlock
class RWLock: public RWLockType {
  public:
    RWLock();
    ~RWLock();

    //Enter a critical region for reading
    void ReadLock();
    //Try to acquire the lock for reading, return true if successful
    bool TryReadLock();
    //Enter a critical region for writing
    void WriteLock();
    //Try to acquire the lock for writing, return true if successful
    bool TryWriteLock();
    //Leave a critical region
    void Unlock();

  private:
    pthread_rwlock_t l;
};

} //namespace threads

#endif //RWLOCK_H
