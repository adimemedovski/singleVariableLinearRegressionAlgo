# Single Variable Linear Regression (Simple Linear Regression Model)
## My Approach
I approached linear regression from a mathematical perspective. I understood the concept of a loss function, this then allowed me to connect
my knowledge of Calculus to the principle of minimising the loss function.

I understood that the loss function was simply: 

$$L(m, b) = \frac{1}{n} \sum_{i=1}^{n} (y_{i} - \hat{y}_{i})^{2} \quad (1.1)$$

where $\hat{y}$ is the predicted dependent variable at each data point, and $y_{i}$ is the actual value of the dependent variable at the $i-$th datapoint.

We can rewrite $(1.1)$ as:

$$L(m, b) = \frac{1}{n} \sum_{i=1}^{n} (y_{i} - m x_{i} - b)^{2} \ (1.2)$$

Now, a large problem in linear regression is minimising this loss function. Because this is a simple linear regression model (consisting 
of a single independent variable), we can optimally apply the concept of partial derivatives in solving this problem.

Taking the partial derivative of $L$ with respect to the slope, $m$, yields:

$$
\begin{aligned}
\frac{\partial L}{\partial m}
&= \frac{\partial}{\partial m}
\left[
\frac{1}{n}
\sum_{i=1}^{n}
\left(y_i - mx_i - b\right)^2
\right]
\\
&= \frac{1}{n}
\sum_{i=1}^{n}
2\left(y_i - mx_i - b\right)(-x_i)
\\
&= -\frac{2}{n}
\sum_{i=1}^{n}
x_i\left(y_i - mx_i - b\right)
\end{aligned}
\qquad (1.3)
$$

Now, we take the partial derivative of $L$ with respect to the intercept, $b$, this yields: 

$$
\begin{aligned}
\frac{\partial L}{\partial b}
&= \frac{\partial}{\partial b}
\left[
\frac{1}{n}
\sum_{i=1}^{n}
\left(y_i - mx_i - b\right)^2
\right]
\\
&= \frac{1}{n}
\sum_{i=1}^{n}
2\left(y_i - mx_i - b\right)(-1)
\\
&= -\frac{2}{n}
\sum_{i=1}^{n}
\left(y_i - mx_i - b\right)
\end{aligned}
\qquad (1.4)
$$

Setting both partial derivatives, $(1.3)$ and $(1.4)$ equal to zero gives and performing simplification, we obtain:

$$
-m\sum_{i=1}^{n}x_i^2 - b\sum_{i=1}^{n}x_i + \sum_{i=1}^{n}x_iy_i = 0
\qquad (1.5)
$$

$$
-m\sum_{i=1}^{n}x_i - nb + \sum_{i=1}^{n}y_i = 0
\qquad (1.6)
$$

Now, to find the critical point for which $L$ is minimised, we solve for $b$ in terms of $m$ and plug this back into $(1.5)$ to find $m$:

Solving $(1.6)$ for $b$:

$$
\begin{aligned}
-m\sum_{i=1}^{n}x_i - nb + \sum_{i=1}^{n}y_i &= 0
\\
nb &= \sum_{i=1}^{n}y_i - m\sum_{i=1}^{n}x_i
\\
b &= \frac{\sum_{i=1}^{n}y_i - m\sum_{i=1}^{n}x_i}{n}
\end{aligned}
\qquad (1.7)
$$

Substituting $(1.7)$ into $(1.5)$:

$$
\begin{aligned}
-m\sum_{i=1}^{n}x_i^2 - \left(\frac{\sum_{i=1}^{n}y_i - m\sum_{i=1}^{n}x_i}{n}\right)\sum_{i=1}^{n}x_i + \sum_{i=1}^{n}x_iy_i &= 0
\\
-nm\sum_{i=1}^{n}x_i^2 - \left(\sum_{i=1}^{n}y_i - m\sum_{i=1}^{n}x_i\right)\sum_{i=1}^{n}x_i + n\sum_{i=1}^{n}x_iy_i &= 0
\\
-nm\sum_{i=1}^{n}x_i^2 - \sum_{i=1}^{n}x_i\sum_{i=1}^{n}y_i + m\left(\sum_{i=1}^{n}x_i\right)^2 + n\sum_{i=1}^{n}x_iy_i &= 0
\\
m\left[\left(\sum_{i=1}^{n}x_i\right)^2 - n\sum_{i=1}^{n}x_i^2\right] &= \sum_{i=1}^{n}x_i\sum_{i=1}^{n}y_i - n\sum_{i=1}^{n}x_iy_i
\\
m &= \frac{n\sum_{i=1}^{n}x_iy_i - \sum_{i=1}^{n}x_i\sum_{i=1}^{n}y_i}{n\sum_{i=1}^{n}x_i^2 - \left(\sum_{i=1}^{n}x_i\right)^2}
\end{aligned}
\qquad (1.8)
$$

Finally, the two important results: 

$$
m =
\frac{
n\sum_{i=1}^{n}x_iy_i - \sum_{i=1}^{n}x_i\sum_{i=1}^{n}y_i
}{
n\sum_{i=1}^{n}x_i^2 - \left(\sum_{i=1}^{n}x_i\right)^2
}
\qquad (1.9)
$$

and

$$
b =
\frac{
\sum_{i=1}^{n}y_i - m\sum_{i=1}^{n}x_i
}{n}
\qquad (1.10)
$$

are what allow us to directly calculate the gradient, $m$, and intercept, $b$ for which our loss function is minimised. This is in particular the results I made use of within my program. 

## Reflections
It really helped in approaching linear regression from this mathematical perspective as a beginner, as it does not suggest you rely on intuition, or animations depicting linear regression, but rather rigorous mathematical derivations.

I'd like to further explore regression from the standpoint of multiple independent variables in my next project, also through a mathematical lens. 
