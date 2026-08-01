/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/

#include <iostream>
#include "TransformationRegistry.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"
#include "BatchPipeline.h"
#include "PostgresFactory.h"
#include "CheckpointManager.h"

void print(std::string message)
{
    std::cout << message << std::endl;
}

void test()
{

    // (1)

    TransformationRegistry *transformationRegistry = new TransformationRegistry();
    transformationRegistry->registerStep("dedup", new DeduplicateStep());
    transformationRegistry->registerStep("aggregate", new AggregateByRegionStep());

    // (2)

    Pipeline *pipeline = new BatchPipeline(new PostgresFactory());

    // (3)

    pipeline->addStep(transformationRegistry->create("dedup"));
    pipeline->addStep(transformationRegistry->create("aggregate"));

    // (4)

    CheckpointManager *checkpointManager = new CheckpointManager();

    // (5)

    pipeline->run();
    RunCheckpoint *checkpoint = pipeline->createCheckpoint();
    checkpointManager->save(checkpoint);

    // (6)

    delete transformationRegistry;
    delete pipeline;
    delete checkpointManager;
}

int main()
{
    print("Starting test...");

    test();

    print("Test complete");

    return 0;
}