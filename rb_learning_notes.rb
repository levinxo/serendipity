#!/usr/bin/env ruby

#-----------------------
# everything is object
# 点号之前的东西称为接收者，点号后面的名字是被调用的方法
# 方法通过向对象发送消息来唤起调用

def hello(name)
  "Hello, #{name.capitalize}"
end

puts hello('levin')
puts 'levin'.length
puts -8.abs
puts 'levin'.index('v')

#-----------------------
# array literal

words_array = ['cat', 'dog']
puts words_array

words_array = %w{cat dog}
puts words_array

#-----------------------
# hash literal
# 此处和php数组一样的结构

words_hash = {
  'a' => 'hello',
  'b' => 'world',
}

puts words_hash

#-----------------------
# control structures

if 5 > 3
  puts 'ret 1'
elsif 5 == 3
  puts 'ret 2'
else
  puts 'ret 3'
end

puts 'hello' if 1

square = 2
square = square*square while square < 100
puts square

#-----------------------
# regex

if 'ruby' =~ /r\w*y/
  puts 'match'
end

puts 'python'.sub(/python/, 'ruby')
puts 'pythonpython'.gsub(/python/, 'ruby')

#-----------------------
# block yield

def call_block
  yield('hello')
end

call_block { | word | puts word }









