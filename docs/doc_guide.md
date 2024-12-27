# Documentation Guide for EasyLibrary

Guide to documentation of code in the library.

## Function signatures

When concept documentation or other requirements specify a function signature.

- Return Type:
    - When specified, the return type of the function must be as given (will be enforced by compiler in case of concept requirements).
    - A return type enclosed in `[]` indicates that the function must have a return type implicitly convertible to the specified type to satisfy the requirement.

- Argument Types:
    - When specified, the argument type must be as given (may not be enforced by compiler, as long as the function argument is implicitly convertible from the type specified).
    - An argument (function or template) type enclosed in `[]` indicates that the function argument type must be implicitly convertible from the type specified to satisfy the argument.
    - An argument (function or template) type with `[const]` prefix and `[&]` suffix indicates that the function may be called by value or by constant reference.
    - An argument (function or template) type with `[&&]` suffix indicates that the function may be called by value or by rvalue reference.

eg: `[std::string_view] to_string([int] value) const noexcept`
Requires a method `to_string` which takes an argument that can be constructed from `int` (eg `long` is acceptable) and returns a type that can be implicitly converted to `std::string_view`, `std::string to_string(long value) const noexcept` is a method that will satisfy this requirement.

## Branch Naming

- master - stable release (except 1.0.1 alpha).
- develop - latest features and fixes
- bs-{} - build system (cmake) updates to features, implementation.
- feature-{} - feature branch
- fix-{} - bug fix branch
- release-{} - release management branch (modify version info, documentation, cleanup)



<hr/>
<p style="text-align: center;">
Part of Project EasyLibrary
Copyright &copy; Harith Manoj <br>
Licensed under Apache License, version 2.0 <br></p>

See [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0) for copy of license or attached LICENSE text file.

<hr/>