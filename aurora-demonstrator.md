# Aurora demonstrators

# Use case 1: DYNAMICALLY REASSIGNING RESOURCES

## Scenario:

A set of production jobs of kind
"build/mesostest/devel/data-taking-test" are deployed. They are doing
a CPU intensive job for 100 seconds and then they sleep for another
100 seconds. We want that a second set of CPU intensive jobs, namely
"build/mesostest/devel/simulation-test" take over when the resources are
available but do not interphere when the former jobs are running.

## Simulation:

- The production jobs are started with:

      aurora job create build/mesostest/devel/data-taking-test usecase-1.aurora

- The ad-hoc jobs are started with:

      aurora job create build/mesostest/devel/simulation-test usecase-1.aurora

## Results:

## TODO:

- We need a simple time consuming benchmark to simulate "simulation-test".
- We need a simple alternating job to simulate the "data-taking" job.
- We need a plot with the actual CPU usage of the first set of jobs, it should
  look like a squared wave plot.
- We need a plot of the actual CPU usage of the second set of jobs, it should be a flat line.
- We need a plot of the acual CPU usage of the first set of jobs when
  also the second set is running, it should still be a flat line.
- We need a plot of the actual CPU usage of the second set of jobs when
  the first one is running, it should be a squared wave as well, given
  they should get less CPU when the first one is active.
