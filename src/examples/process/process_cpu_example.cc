#include <iostream>
#include <string>

#include "base/at_exit.h"
#include "base/command_line.h"
#include "base/process/process.h"
#include "base/process/process_metrics.h"
#include "base/run_loop.h"
#include "base/task/post_task.h"
#include "base/task/thread_pool/thread_pool_instance.h"
#include "base/task_runner.h"
#include "base/test/task_environment.h"
#include "base/test/test_timeouts.h"

void GetProcessCpuUsage(int process_id) {}

int main(int argc, char** argv) {
  return 0;
}
