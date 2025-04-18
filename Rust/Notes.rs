/* Trait like params and return value */

{
    trait ITest {}
    struct MyStruct {}
    impl ITest for MyStruct {}

    fn getFoo(field: &impl ITest) {}
    fn retFoo() -> impl Itest {}
}

/*----------------------------------*/

/* trait bound */

{
    trait ITest {}
    trait OneMoreTrait {}

    // insted this
    fn display(field: &impl ITest) {}
    // this
    fn display<T: ITest>(field: &T) {}
    //also posible do this
    fn display<T>(field: &T) where T: ITest {}
    // and one more case
    fn display(field: &(impl ITest + OneMoreTrait)) {}
}

/*----------------------------------*/

/* Gobal impl trait */

{
    struct MyStruct {}

    trait ITest {}

    impl<T> ITest for T {
        fn traitFoo(&self) {}
    }

    fn foo() {
        let obj = MyStruct{};
        obj.traitFoo();
    }
}

/*----------------------------------*/

/* Operators overloads*/

    // full list of operators:
    // https://doc.rust-lang.org/std/ops/index.html.

{
    use std::ops::Add;

    struct MyStruct {
        value: u32
    }

    impl Add for Counter {
        type Output = Counter;
        fn add(self, other: Counter) -> Counter {
            Output {
                value: self.value + other.value
            }
        }
    }

    fn test() {
        let counter1 = Counter{value: 1.to_owned()};
        let counter2 = Counter{value: 1.to_owned()};

        let res: Coutner = counter1 + counter2;
    }
}

/*----------------------------------*/

/* type */

{
    trait ITest {
        type Unit;
        fn foo() -> Self::Unit;
    }

    struct MyStruct {}

    impl Itest for MyStruct {
        type Unit = i32;
        fn foo() -> Self::Unit {
            /* ... */
        }
    }
}

/*----------------------------------*/

/* Polimorphism */

{
    trait ITest {
        fn foo(&self);
    }

    struct MyStruct {}
    struct OneMoreStruct {}

    impl ITest for MyStruct {
        fn foo(&self) {
            /* ... */
        }
    }
    impl ITest for OneMoreStruct {
        fn foo(&self) {
            /* ... */
        }
    }

    fn test() {
        let my = MyStruct {};
        let one = OneMoreStruct {};

        let vec: Vec<&dyn ITest> = vec![&my, &one];
        
        for elem in vec {
            elem.foo();
        }
    }
}

/*----------------------------------*/

/* Ref lifetime */

{
    fn foo() -> &'a str {
        /* ... */
    }

    fn foo<'a>(first: &'a str, second: &'a str) -> &'a str {
        /* ... */
    }

    struct MyStruct<'a> {
        field: &'a str,
    }

    fn test() {
        let somStr = "some".to_owned();
        let temp = MyStruct{ field: &domeStr };
    }

    impl<'a> MyStruct<'a> {
        fn memberFoo(&self) {
            println!(self.field);
        }

        fn oneMore<'b>(&self, other: 'b str) -> &'b str {
            other
        }
    }
}

/*----------------------------------*/

/* Iterator */

{
    trait Iterator {
        type Item;
        fn next(&mut self) -> Option<Self::Item>;
    }

    struct Counter {
        count: u32,
    }

    impl Iterator for Counter {
        type Item = u32;
        
        fn next(&mut self) -> Option<Self::Item> {
            if self.coutn < 10 {
                self.count += 1;
                Some(self.count)
            } else {
                None
            }
        }
    }

    fn test() {
        let mut counter = Counter { count: 0 };
        for num in &mut counter {
            println!("Num: {}", num);
        }
    }

    trait IntoIterator {
        type Item;
        type IntoIter = std::vec::IntoIter<Self::Item>;
        fn into_iter(self) -> Self::IntoIter;
    }

    impl IntoIterator for Counter {
        type Item = u32;
        type IntoIter = std::vec::IntoIter<Self::Itme>;
        fn into_iter(self) -> Self::IntoIter {
            self.count.into_iter()
        }
    }
}

/*----------------------------------*/