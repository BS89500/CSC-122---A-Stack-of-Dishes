#include <string>

class Dish {
  private:
    std::string description;

  public:
    Dish(std::string description) {
      this->description = description;
    }

    std::string get_description() {
      return this->description;
    }
}
