-- ������ Ÿ���� ����Ʈ�� �Է� �޾Ƽ� ������ Ÿ���� ��ȯ
myHead :: [a] -> a
myHead [] = error "myHead empty list"
myHead (x:xs) = x

addTwo :: Num a => [a] -> a
addTwo (x:y:xs) = (x+y)

addSpace :: [Char] -> [Char]
--addSpace (' ':xs) = ' ':xs
addSpace str@(' ':xs) = str  -- as ����
addSpace xs = ' ':xs

translate :: Int -> String
--{
translate 1 = "one"
translate 2 = "two"
translate 3 = "three"
translate 4 = "other"
--}

-- C ����� case �� ó��
translate x = "result is " ++ case x of 1 -> "one"
                                        2 -> "two"
                                        3 -> "three"
                                        _ -> "other"
