# Fault Detection using Bayes' Theorem

## 📚 Problem Statement
A manufacturing unit uses a sensor system to detect faults in its machines.  
Based on historical data:
- Only **2%** of the machines develop faults on any given day.
- If a machine **has a fault**, the sensor correctly detects it with **98%** accuracy (**True Positive Rate**).
- If a machine **does not have a fault**, the sensor incorrectly signals a fault in **3%** of the cases (**False Positive Rate**).

One morning, a machine’s sensor gives a fault alert.  
**Question:** What is the probability that the machine actually has a fault?

---

## 🧠 Concept Used: Bayes' Theorem

Bayes' theorem allows us to update the probability of an event based on new evidence.

The basic formula:

\[
P(A|B) = \frac{P(B|A) \times P(A)}{P(B)}
\]

Where:
- \( P(A|B) \) = Probability of fault given alert
- \( P(B|A) \) = Probability of alert given fault
- \( P(A) \) = Probability of fault
- \( P(B) \) = Overall probability of an alert happening

---

## 🛠 Steps to Solve

1. **Calculate** \( P(\text{No Fault}) = 1 - P(\text{Fault}) \)
2. **Find** the total probability of getting an alert:

\[
P(\text{Alert}) = (P(\text{Alert}|\text{Fault}) \times P(\text{Fault})) + (P(\text{Alert}|\text{No Fault}) \times P(\text{No Fault}))
\]

3. **Apply** Bayes' Theorem to find:

\[
P(\text{Fault}|\text{Alert}) = \frac{P(\text{Alert}|\text{Fault}) \times P(\text{Fault})}{P(\text{Alert})}
\]

---

## 🧮 Calculations

Given:
- \( P(\text{Fault}) = 0.02 \)
- \( P(\text{No Fault}) = 0.98 \)
- \( P(\text{Alert}|\text{Fault}) = 0.98 \)
- \( P(\text{Alert}|\text{No Fault}) = 0.03 \)

Finding \( P(\text{Alert}) \):

\[
P(\text{Alert}) = (0.98 \times 0.02) + (0.03 \times 0.98)
\]
\[
= 0.0196 + 0.0294 = 0.049
\]

Now applying Bayes’ theorem:

\[
P(\text{Fault}|\text{Alert}) = \frac{0.0196}{0.049} \approx 0.4
\]

Thus, the probability is **40%**.
