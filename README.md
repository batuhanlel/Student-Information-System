# Student-Information-System
**Subject :** Creating a small scale and file based Student Information System based on the logic of relational databases in C

*Note1 : Before programme starts, there is already a set of data you can work with. But if you want to add data from scratch, you can just go with empty text files and start adding data with respect to dependencies.*

*Note2 : After programme stars you are expected to enter the maximum number of course and credit can be taken by a student*

## Scope of Application
- Courses Text
  - 'Courses' text includes following attributes; 
    - Unique course code
    - Course name
    - Course credit
    - Course quota
    - Lecturer ID
  - Adding, deleting and updating courses possible.
- Lecturer Text
  - 'Lecturer' text includes following attributes;
    - Unique lecturer ID
    - Lecturer name
    - Lecturer surname
    - Lecturer title  
  - Adding, deleting and updating lecturers possible.
- Student Text
  - 'Student' text includes following attributes;
    - Unique student ID
    - Student name
    - Student surname
    - Total number of enrolled courses  
    - Total number of credits taken
  - Adding, deleting and updating students possible.
  - Course Enrollment and course drop possible.
- Since one student can enroll more than one course and one course can have more than one student enrolled in that course, **StudentCourseEnroll** text should store which student takes which course with respect to <StudentID-CourseCode> matching. 
  - There must be an auto-incrementing unique ID starts from 1 for each match. 
  - 'StudentCourseEnroll' text includes following attributes;
    - Unique ID
    - Student ID
    - Course code
    - Student enrollment status (Enrolled / Dropped)
    - Date of operation
 
 What other features we have? Here is all;
  1. You can list the courses given by the lecturer whose ID is given.
  2. You can list all students enrolled in a course whose course code is given.
  3. You can list all courses taken by a students whose student ID is given.
  4. You can create a class list for a given course code and it's lecturer ID and save that list in 'CourseCode'_ClassList.txt file.
