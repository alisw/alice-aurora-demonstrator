## Simple hello world

A simple hello world example can be found at:

<https://github.com/alisw/alice-aurora-demonstrator/blob/master/example.aurora>

## Using revocable resources

An adapted version of the hello world example to use revocable resources can be
found at

<https://github.com/alisw/alice-aurora-demonstrator/blob/master/example-revocable.aurora>

Notice the only thing you have to do is to add `tier=revocable`. These jobs
will be automatically killed and their resources redeemed if the Mesos QoS
system decides so (e.g. if the load of the machine is too high).

## Launching a docker container

Mesos / Aurora support launching jobs inside a specified docker
container, even without having the docker runtime available on the agent
machine. You can find an example of how to do so at:

<https://github.com/alisw/alice-aurora-demonstrator/blob/master/example-docker.aurora>

This boils down to the line:

    container = Mesos(image=DockerImage(name='ubuntu', tag='latest'))

which tells mesos to use the latest Ubuntu docker image for the task.
Notice the image must provide python2.7 so that the aurora executor
itself can run.
