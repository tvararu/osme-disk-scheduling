#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

int compare (const void *a, const void *b) {
  return ( *(int*)a - *(int*)b );
}

struct node {
  int cylinder;
  bool visited;
};

int main () {
  int v[] = { 98, 183, 37, 122, 14, 124, 65, 67 };
  const int MAX_SIZE = 200;
  int init = 53;
  int len = sizeof(v) / sizeof(v[0]), i;

  // FCFS.
  int diff = abs(v[0] - init);
  for (i = 1; i < len; i++) {
    diff += abs(v[i] - v[i - 1]);
  }
  cout << "FCFS: " << diff << endl;

  // SSTF.
  vector<int> sstf;
  sstf.assign(v, v + len);
  sort(sstf.begin(), sstf.end());
  diff = 0;
  int prev = init;
  while (!sstf.empty()) {
    int min = 0x7fffffff;
    for (i = 0; i < sstf.size(); i++) {
      int curr = abs(prev - sstf[i]);
      if (curr < min) {
        min = curr;
      } else {
        diff += min;
        prev = sstf[i - 1];
        break;
      }
    }
    sstf.erase(sstf.begin() + i - 1);
  }
  cout << "SSTF: " << diff << endl;

  // SCAN.
  vector<int> scan;
  scan.assign(v, v + len);
  sort(scan.begin(), scan.end());
  diff = 0;
  prev = init;
  int closestIndex = 0;
  for (i = 0; i < scan.size(); i++) {
    if (init < scan[i]) {
      break;
    }
    closestIndex = i;
  }
  while (!scan.empty()) {
    diff += abs(prev - scan[closestIndex]);
    prev = scan[closestIndex];
    scan.erase(scan.begin() + closestIndex);
    if (closestIndex > 0) {
      closestIndex--;
    }
  }
  cout << "SCAN: " << diff << endl;

  // CSCAN.
  vector<int> cscan;
  cscan.assign(v, v + len);
  sort(cscan.begin(), cscan.end());
  diff = 0;
  prev = init;
  closestIndex = 0;
  cscan.insert(cscan.begin(), 0);
  cscan.insert(cscan.end(), MAX_SIZE);
  for (i = 0; i < cscan.size(); i++) {
    if (init < cscan[i]) {
      break;
    }
    closestIndex = i;
  }
  int dir = -1;
  while (!cscan.empty()) {
    if (prev > cscan[closestIndex]) {
      diff += abs(prev - cscan[closestIndex]);
    }
    prev = cscan[closestIndex];
    cscan.erase(cscan.begin() + closestIndex);
    if (dir < 0) {
      closestIndex--;
    } else {
      closestIndex = cscan.size() - 1;
    }
    if (closestIndex == 0) {
      dir = 1;
    }
  }
  cout << "CSCAN: " << diff << endl;

  // CLOOK.
  vector<int> clook;
  clook.assign(v, v + len);
  sort(clook.begin(), clook.end());
  diff = 0;
  prev = init;
  closestIndex = 0;
  for (i = 0; i < clook.size(); i++) {
    if (init < clook[i]) {
      break;
    }
    closestIndex = i;
  }
  dir = -1;
  while (!clook.empty()) {
    if (prev > clook[closestIndex]) {
      diff += abs(prev - clook[closestIndex]);
    }
    prev = clook[closestIndex];
    clook.erase(clook.begin() + closestIndex);
    if (dir < 0) {
      closestIndex--;
    } else {
      closestIndex = clook.size() - 1;
    }
    if (closestIndex == 0) {
      dir = 1;
    }
  }
  cout << "CLOOK: " << diff << endl;

  return 0;
}
