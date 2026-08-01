/*
    Caleb Jennings, u25173805
    Chloe Larsen, u25004141
*/

#include <iostream>
#include "TransformationRegistry.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"
#include "BatchPipeline.h"
#include "StreamingPipeline.h"
#include "PostgresFactory.h"
#include "CheckpointManager.h"

void print(std::string message)
{
    std::cout << message << std::endl;
}

void main6StepTest()
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

void testTransformationRegistry()
{
    TransformationRegistry *transformationRegistry = new TransformationRegistry();
    Transformation *transformation = new DeduplicateStep();
    transformationRegistry->registerStep("dedup", transformation);
    transformationRegistry->registerStep("dedup", transformation);        // register same instance again
    transformationRegistry->registerStep("dedup", new DeduplicateStep()); // register new under same key

    delete transformationRegistry;
}

void testCheckpointRestoration()
{
    TransformationRegistry *transformationRegistry = new TransformationRegistry();
    transformationRegistry->registerStep("dedup", new DeduplicateStep());
    transformationRegistry->registerStep("aggregate", new AggregateByRegionStep());

    Pipeline *pipeline = new StreamingPipeline(new PostgresFactory());

    pipeline->addStep(transformationRegistry->create("dedup"));
    pipeline->addStep(transformationRegistry->create("aggregate"));

    CheckpointManager *checkpointManager = new CheckpointManager();

    pipeline->run();
    RunCheckpoint *checkpoint = pipeline->createCheckpoint();
    checkpointManager->save(checkpoint);
    RunCheckpoint *undoneCheckpoint = checkpointManager->undo();
    checkpointManager->undo(); // trigger empty condition
    pipeline->restore(undoneCheckpoint);

    delete transformationRegistry;
    delete pipeline;
    delete checkpointManager;
}

void testTransformations()
{
    Transformation *a = new AggregateByRegionStep();
    Transformation *b = new DeduplicateStep();

    a->getName();
    a->apply({"one", "two", "three"});

    b->getName();
    b->apply({"one", "two", "three"});
}

int main()
{
    print("Starting test...");

    main6StepTest();
    testTransformationRegistry();
    testCheckpointRestoration();
    testTransformations();

    print("Test complete");

    return 0;
}