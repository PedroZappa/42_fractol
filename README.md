<a name="readme-top"></a>
<div align="center">

# Fract'ol

 This project is about creating graphically beautiful fractals.

<p>
    <img src="https://img.shields.io/badge/score-%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/PedroZappa/42_minitalk?style=for-the-badge&logo=github">
    <img src="https://img.shields.io/github/languages/count/PedroZappa/42_minitalk?style=for-the-badge&logo=" />
    <img src="https://img.shields.io/github/languages/top/PedroZappa/42_minitalk?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/PedroZappa/42_minitalk?style=for-the-badge" />
</p>

___

<h3>Table o'Contents</h3>

</div>

<!-- mtoc-start -->

* [About](#about)
  * [The Math ](#the-math-)
    * [Complex Numbers](#complex-numbers)
    * [Complex Arithmetic](#complex-arithmetic)
      * [Addition](#addition)
      * [Subtraction](#subtraction)
      * [Multiplication](#multiplication)
        * [Complex * Real](#complex--real)
        * [Complex * Complex](#complex--complex)
* [Implementation](#implementation)
* [Usage](#usage)
* [License](#license)

<!-- mtoc-end -->

## About

Fract'ol is the first graphics project of the Common Core curriculum. A simple implementation of computer graphics using the `minilibx` a simplified version of `Xlib`.

This project is an opportunity to learn how to use the mathematical notion of **complex numbers**, have a first contact with the concept of **optimization** in computer graphics, and **event handling**. 

### The Math 

#### Complex Numbers

`Complex numbers` are numbers in the form `a + bi` where `a` is the real part and `b` is the imaginary part and `i` is the imaginary unit, defined by the equation $i^2 = -1$.

The real part of a complex number is mapped to the `x` axis and the imaginary part to the `y` axis describing a 2D grid, the `Complex Plane`. 

#### Complex Arithmetic

Like with real numbers, we can perform **arithmetic** on complex numbers.

##### Addition

> $(a + bi) + (c + di) = (a + c) + (b + d)i$

Example of how to add two complex numbers:

> $((3 - 4i) + (2 + 5i)) =$
>
> $((3 + 2) + (-4 + 5)i) =$
>
> $(5 + i)$

##### Subtraction

> $(a + bi) - (c + di) = (a - c) + (b - d)i$

##### Multiplication

Multiplication is similar to multiplying binomials but with complex numbers we work with the real and imaginary parts separately.

###### Complex * Real

> $c(a + bi) = (c * a) + (c * b)i$

Example:

> $3(6 + 2i) =$
>
> $(3 * 6) + (3 * 2i) =$ # Distribute
>
> $(18 * 6i)$ # Simplify

###### Complex * Complex

> $(a + bi)(c + di) = ac + adi + bci + bdi^2$

* Because $i^2 = -1$, we can simplify the expression to:

> $(a + bi)(c + di) = ac + adi +bci - bd$

* Simplifying, we combine the real parts, and then the imaginary parts:

> $(a + bi)(c + di) =$
> 
> $(ac - bd) + (ad + bc)i$

Example:

> $(4 + 3i)(2 - 5i) =$
>
> $(4 * 2) + (4 * (-5i)) + (3i * 2) + (3i * (-5i)) =$
>
> $8 - 20i + 6i - 15i^2 =$
>
> $8 + 15 - 20i + 6i =$
>
> $(23 - 14i)$

___
## Implementation

___
## Usage

___
## License

This work is published under the terms of <a href="https://github.com/PedroZappa/42_fractol/blob/main/LICENSE">42 Unlicense</a>.

<p align="right">(<a href="#readme-top">get to top</a>)</p>

