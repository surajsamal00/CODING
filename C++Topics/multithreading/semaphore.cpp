#include <bits/stdc++.h>


class Semaphore {
private:
    int count;
    std::mutex mtx;
    std::condition_variable cv;

public:
    Semaphore(int n) : count(n) {}

    void wait() {
        std::unique_lock<std::mutex> lock(mtx);          // Acquire mutex
        cv.wait(lock, [this]() { return count > 0; });   // Sleep until count > 0
                                                        // **Mutex is automatically released while sleeping**
                                                        // **Mutex is automatically reacquired when waking**
        count--;                                         // Take one resource (safe because mutex held)
    } // lock goes out of scope -> mutex released


    void signal() {
        std::unique_lock<std::mutex> lock(mtx);     // Acquire mutex
        count++;                                    // Increment resource count
        cv.notify_one();                            // Wake one waiting thread
                                                    // **Mutex is NOT released here**  
                                                    // Mutex is still held until lock goes out of scope
    } // lock goes out of scope -> mutex released

};
