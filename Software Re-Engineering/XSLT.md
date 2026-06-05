# XSLT

A practical guide to understanding XSLT and XPath quickly.

## What is XSLT?

**XSLT (Extensible Stylesheet Language Transformations)** is a language used to transform XML documents into other formats such as:

- HTML
- XML
- Plain text
- SQL scripts
- Java code
- CSV files

Unlike Java or Python, XSLT is **declarative**. You describe _what should be produced_, not _how to iterate through every step_.

---

# 1. Basic XSLT Structure

Every XSLT document follows the same basic pattern:

```xml
<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet>

    <xsl:output method="text" encoding="UTF-8"/>

    <xsl:template match="/">
        <!-- Processing starts here -->
    </xsl:template>

</xsl:stylesheet>
```

## Important Parts

### Root Element

```xml
<xsl:stylesheet>
```

Defines the document as an XSLT stylesheet.

### Output Method

```xml
<xsl:output method="text"/>
```

Common values:

| Method | Output                |
| ------ | --------------------- |
| text   | Plain text, SQL, Java |
| xml    | XML                   |
| html   | HTML                  |

### Entry Point

```xml
<xsl:template match="/">
```

Equivalent to a `main()` function.

Processing starts at the root of the XML document.

---

# 2. XPath Fundamentals

XPath is used inside XSLT to locate data.

Consider this XML:

```xml
<Students>
    <Student id="101">
        <Name>Ali</Name>
        <Age>20</Age>
    </Student>
</Students>
```

## Common XPath Expressions

| XPath       | Meaning               |
| ----------- | --------------------- |
| `Student`   | Child element         |
| `@id`       | Attribute             |
| `.`         | Current node          |
| `..`        | Parent node           |
| `*`         | All child elements    |
| `//Student` | Find Student anywhere |

---

## Example: Reading Data

XML:

```xml
<Student id="101">
    <Name>Ali</Name>
</Student>
```

XSLT:

```xml
<xsl:value-of select="@id"/>
```

Output:

```text
101
```

XSLT:

```xml
<xsl:value-of select="Name"/>
```

Output:

```text
Ali
```

# 3. Attributes vs Elements

## Attribute

XML:

```xml
<Student id="101"/>
```

Access:

```xpath
@id
```

## Element

XML:

```xml
<Student>
    <id>101</id>
</Student>
```

Access:

```xpath
id
```

No `@` is used.

---

# 4. Printing Values

Use:

```xml
<xsl:value-of select="XPath"/>
```

Example:

```xml
<xsl:value-of select="Name"/>
```

Input:

```xml
<Name>Ali</Name>
```

Output:

```text
Ali
```

---

# 5. Loops with xsl:for-each

XML:

```xml
<Students>
    <Student>
        <Name>Ali</Name>
    </Student>
    <Student>
        <Name>Sara</Name>
    </Student>
</Students>
```

XSLT:

```xml
<xsl:for-each select="Students/Student">
    <xsl:value-of select="Name"/>
    <xsl:text>&#10;</xsl:text>
</xsl:for-each>
```

Output:

```text
Ali
Sara
```

---

# 6. Conditions with xsl:if

XML:

```xml
<Student grade="A"/>
```

XSLT:

```xml
<xsl:if test="@grade = 'A'">
    Excellent
</xsl:if>
```

Output:

```text
Excellent
```

## Comparison Operators

| Operator | Meaning               |
| -------- | --------------------- |
| `=`      | Equal                 |
| `!=`     | Not equal             |
| `&lt;`   | Less than             |
| `&gt;`   | Greater than          |
| `&lt;=`  | Less than or equal    |
| `&gt;=`  | Greater than or equal |

Example:

```xml
<xsl:if test="Age &gt;= 18">
    Adult
</xsl:if>
```

---

# 7. if-else with xsl:choose

XSLT does not have an `else` statement.

Use:

```xml
<xsl:choose>
    <xsl:when test="Email">
        Email exists
    </xsl:when>

    <xsl:otherwise>
        No email
    </xsl:otherwise>
</xsl:choose>
```

---

# 8. Filtering with Predicates

Predicates use square brackets.

## Filter by Attribute Existence

XPath:

```xpath
Student[@id]
```

Meaning:

> Select only students that have an id attribute.

---

## Filter by Value

XPath:

```xpath
Student[@grade='A']
```

Meaning:

> Select only students whose grade is A.

---

## Example

XML:

```xml
<Students>
    <Student grade="A"/>
    <Student grade="B"/>
    <Student grade="A"/>
</Students>
```

XSLT:

```xml
<xsl:for-each select="Student[@grade='A']">
```

Processes only:

```xml
<Student grade="A"/>
<Student grade="A"/>
```

---

# 9. Useful XPath Functions

## position()

Returns current item number.

Example:

```xml
<xsl:value-of select="position()"/>
```

Output:

```text
1
2
3
...
```

---

## last()

Returns total number of selected items.

Example:

```xml
<xsl:value-of select="last()"/>
```

Output:

```text
5
```

if there are five selected nodes.

---

## name()

Returns the tag name.

XML:

```xml
<CPU>90</CPU>
```

XSLT:

```xml
<xsl:value-of select="name()"/>
```

Output:

```text
CPU
```

---

# 10. Avoiding the Trailing Comma Problem

Goal:

```sql
id INT,
name TEXT,
age INT
```

Not:

```sql
id INT,
name TEXT,
age INT,
```

Solution:

```xml
<xsl:if test="position() != last()">,</xsl:if>
```

Example:

```xml
<xsl:for-each select="attribute">
    <xsl:value-of select="@name"/>

    <xsl:if test="position() != last()">
        ,
    </xsl:if>
</xsl:for-each>
```

---

# 11. Whitespace and New Lines

XSLT often removes formatting whitespace.

## Insert a Space

```xml
<xsl:text> </xsl:text>
```

---

## Insert a New Line

```xml
<xsl:text>&#10;</xsl:text>
```

Example:

```xml
<xsl:value-of select="Name"/>
<xsl:text>&#10;</xsl:text>
```

---

# 12. Templates and apply-templates

Large XSLT projects usually use templates instead of nested loops.

## Main Template

```xml
<xsl:template match="/">
    <xsl:apply-templates select="//Student"/>
</xsl:template>
```

---

## Student Template

```xml
<xsl:template match="Student">
    <xsl:value-of select="Name"/>
</xsl:template>
```

Think of it like:

| XSLT            | Programming Analogy |
| --------------- | ------------------- |
| apply-templates | Function call       |
| template match  | Function definition |

---

# Example 1: Generate SQL INSERT Statements

Input XML:

```xml
<Students>
    <Student>
        <Name>Ali</Name>
        <Age>20</Age>
    </Student>

    <Student>
        <Name>Sara</Name>
        <Age>22</Age>
    </Student>
</Students>
```

XSLT:

```xml
<xsl:template match="/">
    <xsl:for-each select="Students/Student">
        INSERT INTO Student VALUES (
        '<xsl:value-of select="Name"/>',
        <xsl:value-of select="Age"/>
        );
        <xsl:text>&#10;</xsl:text>
    </xsl:for-each>
</xsl:template>
```

Output:

```sql
INSERT INTO Student VALUES ('Ali', 20);
INSERT INTO Student VALUES ('Sara', 22);
```

---

# Example 2: Generate HTML

Input XML:

```xml
<Students>
    <Student>
        <Name>Ali</Name>
    </Student>
    <Student>
        <Name>Sara</Name>
    </Student>
</Students>
```

XSLT:

```xml
<xsl:output method="html"/>

<xsl:template match="/">
    <ul>
        <xsl:for-each select="Students/Student">
            <li>
                <xsl:value-of select="Name"/>
            </li>
        </xsl:for-each>
    </ul>
</xsl:template>
```

Output:

```html
<ul>
  <li>Ali</li>
  <li>Sara</li>
</ul>
```

---

# Example 3: Generate Java Classes

Input XML:

```xml
<model>
    <class name="Person"/>
    <class name="Student" parent="Person"/>
</model>
```

XSLT:

```xml
<xsl:for-each select="model/class">
    class <xsl:value-of select="@name"/>

    <xsl:if test="@parent">
        extends <xsl:value-of select="@parent"/>
    </xsl:if>

    {}
</xsl:for-each>
```

Output:

```java
class Person {}

class Student extends Person {}
```

---

# XSLT Quick Reference

## Loops

```xml
<xsl:for-each select="Students/Student">
```

## Print Value

```xml
<xsl:value-of select="Name"/>
```

## If

```xml
<xsl:if test="@id">
```

## If-Else

```xml
<xsl:choose>
    <xsl:when test="Age &gt;= 18">
        Adult
    </xsl:when>
    <xsl:otherwise>
        Minor
    </xsl:otherwise>
</xsl:choose>
```

## Apply Templates

```xml
<xsl:apply-templates select="//Student"/>
```

## Current Position

```xml
position()
```

## Total Items

```xml
last()
```

## Current Tag Name

```xml
name()
```

## Attribute

```xpath
@id
```

## Deep Search

```xpath
//Student
```

---

# The 5 Things to Remember

1. XSLT transforms XML into other formats.
2. XPath is used to find data.
3. Attributes use `@`, elements do not.
4. `xsl:for-each` loops through nodes.
5. `position()` and `last()` solve comma-separation problems.
