# Single Variable Linear Regression (Simple Linear Regression Model)
## My Approach
I approached linear regression from a mathematical perspective; I understood the concept of a loss function, and then I made an attempt 
to connect my knowledge in Calculus to the principle of minimising the loss function. 

I understood that the loss function was simply: 

$$L(x, y) = \frac{1}{n} \sum_{i=1}^{n} (y_{i} - \hat{y})^{2} \quad (1.1)$$

where $\hat{y}$ is the predicted linear equation and $y_{i}$ is the value of the dependent variable at each data points index, $i$. In a practical 
sense, this index would simply be each line in the sampleData csv file not including the first line.

We can rewrite $(1.1)$ as:

$$L(x, y) = \frac{1}{n} \sum_{i=1}^{n} (y_{i} - m x_{i} - b)^{2} \ (1.1)$$

Now, a large problem in linear regression is minimising this loss function. Because this is a simple linear regression model (consisting 
of a single independent variable), we can optimally apply the concept of partial derivatives in solving this problem.

Taking the partial derivative of $L$ with respect to the gradient, $m$:

$$
\begin{aligned}
\frac{\partial L}{\partial m}
&= \frac{\partial}{\partial m}
\left[
\frac{1}{h}
\sum_{i = 1}^{n}
\left(y_{i} - mx_{i} - b) \right)^{2}
\right]
\\
\end{aligned}
$$
