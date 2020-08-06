#include <iostream>
#include "base/threading/thread.h"
#include "base/threading/simple_thread.h"


class ThiefThreadRunner : public base::DelegateSimpleThread::Delegate {
 public:
  static std::atomic<int> ati;
  void Run() 
  { 
	std::cout << "thief "<< ati.load() << std::endl;
    ++ati;
  }
};
std::atomic<int> ThiefThreadRunner::ati{0};
int main() {
  base::Thread s("thief");
  s.Start();
  ThiefThreadRunner tr;
  base::SimpleThread::Options op;
  op.joinable = true;
  base::DelegateSimpleThread t(&tr, "thief_delegate_thread", op);
  t.Start();
  t.Join();
  std::cout << t.HasBeenJoined() << std::endl;


  base::DelegateSimpleThreadPool tp("tp_pool", 1);
  tp.AddWork(&tr, 1);
  tp.Start();
  tp.JoinAll();
  base::WaitableEvent we;
  std::cout << "signal before signal: " << we.IsSignaled() << std::endl;
  we.Signal();
  std::cout << "signal after signal: " << we.IsSignaled() << std::endl;
  we.Wait();
  std::cout << "signal after wait: " << we.IsSignaled() << std::endl;
 
}