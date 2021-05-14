

#include <memory>
#include <vector>

int main() {
  int *pia = new int[5];
  std::unique_ptr<int[]> up(new int[10]);
  up.release();

  std::vector<int> vi{12, 3, 4, 5};
  std::allocator<int> alloc;
  auto p = alloc.allocate(vi.size() * 2);
  auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);
  std::uninitialized_fill(vi.begin(), vi.end(), 42);
}
