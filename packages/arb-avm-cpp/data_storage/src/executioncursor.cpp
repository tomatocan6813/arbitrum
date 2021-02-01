/*
 * Copyright 2020, Offchain Labs, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <data_storage/executioncursor.hpp>

#include "value/referencecount.hpp"

#include <data_storage/value/machine.hpp>

void ExecutionCursor::resetExecutionCursor() {
    Checkpoint::resetCheckpoint();
    machine = nullptr;
    first_message_sequence_number = 0;
    messages.clear();
    inbox_hashes.clear();
    messages_to_skip = 0;
}

void ExecutionCursor::setCheckpoint(Checkpoint& checkpoint) {
    Checkpoint::operator=(checkpoint);
}

ExecutionCursor* ExecutionCursor::clone() {
    return new ExecutionCursor(*this);
}

uint256_t ExecutionCursor::machineHash() {
    return machine->hash();
}
std::unique_ptr<Machine> ExecutionCursor::takeMachine() {
    return std::move(machine);
}