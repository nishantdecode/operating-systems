#include <iostream>
#include <vector>
#include <unordered_set>

const int NUM_RESOURCES = 3;

// A class representing a process
class Process {
public:
  Process(int id) : id(id) {}
  int id;
  std::unordered_set<int> resources;
};

// A class representing a resource
class Resource {
public:
  Resource(int id) : id(id) {}
  int id;
  std::unordered_set<int> processes;
};

int main() {
  // Set up the resource allocation graph.
  std::vector<Process> processes;
  std::vector<Resource> resources;
  for (int i = 0; i < NUM_RESOURCES; i++) {
    resources.emplace_back(i);
  }
  for (int i = 0; i < NUM_RESOURCES; i++) {
    processes.emplace_back(i);
  }

  // Allocate resources to processes.
  for (int i = 0; i < NUM_RESOURCES; i++) {
    int p = i % NUM_RESOURCES;
    int r = (i + 1) % NUM_RESOURCES;
    processes[p].resources.insert(r);
    resources[r].processes.insert(p);
  }

  // Print the resource allocation graph.
  std::cout << "Resource allocation graph:\n";
  for (const Process& p : processes) {
    std::cout << "Process " << p.id << ": ";
    for (int r : p.resources) {
      std::cout << r << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  for (const Resource& r : resources) {
    std::cout << "Resource " << r.id << ": ";
    for (int p : r.processes) {
      std::cout << p << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}