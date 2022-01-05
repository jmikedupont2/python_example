#include <pybind11/pybind11.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


class Foo {
public:
  Foo() {}
  std::shared_ptr<Foo> munge() {
    return      
      std::shared_ptr<Foo>(this);
  }
  int munge3() {
    return      2;
  }
  
  std::shared_ptr<Foo> munge2(std::shared_ptr<Foo> f) {
    return std::shared_ptr<Foo>(this);
  }
};

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

autotype(Foo, fooinfo)
autotype(Foo& (*)(Foo*, Foo&), foofunc2)
autotype(Foo& (*)(Foo*), foof3unc2)
autotype(std::shared_ptr<Foo> (*)(Foo*, std::shared_ptr<Foo>), fooconver)

autotype(std::shared_ptr<Foo> (*)(Foo*), fooconvert3)
autotype(int (*)(Foo*),fooint)


#define autotype3(X,Y)				\
const mtype_info Y (  #X  );                    \
template<>					\
constexpr const mtype_info& mtypeid1< X >(){	\
  return Y;                                     \
}                                               \

autotype(std::shared_ptr<Foo>, fooconvert2)


PYBIND11_MODULE(python_example, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: python_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";


      
    py::class_<Foo> foo(m,"Foo");
    foo.def(py::init<>());
    foo.def("munge",&Foo::munge, py::return_value_policy::reference_internal);

    foo.def("munge3",&Foo::munge3);
    foo.def("munge2",&Foo::munge2, py::return_value_policy::reference_internal);

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
